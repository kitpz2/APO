#include "apo_lib.hpp"
#include <iostream>
using namespace std;

unsigned long* Histogram::find_max()
{
    unsigned long *max=new unsigned long[3];//0-r 1-g 2-b
    max[0]=max[1]=max[2]=0;
    greyscale=true;
    for (unsigned int i=0;i<rgb->size;++i)
    {
        if (rgb->r[i]>max[0])
            max[0]=rgb->r[i];

        if (rgb->g[i]>max[1])
            max[1]=rgb->g[i];

        if (rgb->b[i]>max[2])
            max[2]=rgb->b[i];

        if (rgb->r[i]!=rgb->g[i] || rgb->g[i]!=rgb->b[i] || rgb->r[i]!=rgb->b[i])
            greyscale=false;
    }
    return max;
}

void Histogram::scale(unsigned long max_after)
{
    unsigned long *max_before=find_max();
    rescaled_rgb=new data<unsigned long>(false, rgb->size);
    if (greyscale)
    {
        for (unsigned int i=0;i<rgb->size;++i)
        {
            rescaled_rgb->r[i]=(double(rgb->r[i])/double(max_before[0]))*max_after;
        }
    }
    else
    {
        for (unsigned int i=0;i<rgb->size;++i)
        {
            rescaled_rgb->r[i]=(double(rgb->r[i])/double(max_before[0]))*max_after;

            rescaled_rgb->g[i]=(double(rgb->g[i])/double(max_before[1]))*max_after;

            rescaled_rgb->b[i]=(double(rgb->b[i])/double(max_before[2]))*max_after;
        }
    }
}

void Histogram::create_histogram_table(wxImage &obraz)
{
    for (int i=0;i<obraz.GetWidth();++i)
    {
        for (int j=0;j<obraz.GetHeight();++j)
        {
            ++num_of_pixels;
            ++rgb->r[obraz.GetRed(i,j)];
            ++rgb->g[obraz.GetGreen(i,j)];
            ++rgb->b[obraz.GetBlue(i,j)];
        }
    }
    scale();
}

void Histogram::draw_histogram(wxStaticBitmap *hist_r, wxStaticBitmap *hist_g, wxStaticBitmap *hist_b)
{
    wxImage *r, *g, *b;

    if (rescaled_rgb==NULL)
    {
        r=new wxImage(256,256);
        if (hist_r!=NULL)
            hist_r->SetBitmap(*r);
        if (hist_g!=NULL)
            hist_g->SetBitmap(*r);
        if (hist_b!=NULL)
            hist_b->SetBitmap(*r);
        return;
    }

    if (greyscale)
    {
        if (hist_r!=NULL)
        {
            r=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                for (unsigned int j=0;j<rescaled_rgb->r[i];++j)
                {
                    r->SetRGB(i,255-j,175,175,175);
                }
            }
            hist_r->SetBitmap(*r);
            hist_g->Hide();
            hist_b->Hide();
        }
    }
    else
    {

        if (hist_r!=NULL)
        {
            r=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                for (unsigned int j=0;j<rescaled_rgb->r[i];++j)
                {
                    r->SetRGB(i,255-j,255,0,0);
                }
            }
            hist_r->SetBitmap(*r);
        }
        if (hist_g!=NULL)
        {
            g=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                for (unsigned int j=0;j<rescaled_rgb->g[i];++j)
                {
                    g->SetRGB(i,255-j,0,255,0);
                }
            }
            hist_g->SetBitmap(*g);
        }
        if (hist_b!=NULL)
        {
            b=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                for (unsigned int j=0;j<rescaled_rgb->b[i];++j)
                {
                    b->SetRGB(i,255-j,0,0,255);
                }
            }
            hist_b->SetBitmap(*b);
        }
    }
}

Histogram::Histogram(bool empty)
{
    rescaled_rgb=NULL;
    rgb=NULL;
    if (empty)
    {
        rgb=new data<unsigned long>(empty);
        num_of_pixels=0;
    }
    else
    {
        rgb=new data<unsigned long>(empty,256);
        num_of_pixels=0;
    }
};

Histogram::Histogram(wxImage &obraz)
{
    rescaled_rgb=NULL;
    rgb=NULL;
    rgb=new data<unsigned long>(false,256);
    num_of_pixels=0;
    create_histogram_table(obraz);
}

Histogram::~Histogram()
{
    delete [] rgb;
    delete [] rescaled_rgb;
}

Dystrybuanta::Dystrybuanta(Histogram *histogram)
{
    if (histogram!=NULL)
    {
        if (histogram->greyscale)
        {
            greyscale=true;
            rgb=new data<float>(false, 256);
            unsigned long sum_r=0, sum_g=0, sum_b=0;
            for (int i=0;i<256;++i)
            {
                sum_r+=histogram->rgb->r[i];
                rgb->r[i]=float(sum_r)/float(histogram->num_of_pixels);
            }
        }
        else
        {
            greyscale=false;
            rgb=new data<float>(false, 256);
            unsigned long sum_r=0, sum_g=0, sum_b=0;
            for (int i=0;i<256;++i)
            {
                sum_r+=histogram->rgb->r[i];
                rgb->r[i]=float(sum_r)/float(histogram->num_of_pixels);

                sum_g+=histogram->rgb->g[i];
                rgb->g[i]=float(sum_g)/float(histogram->num_of_pixels);

                sum_b+=histogram->rgb->b[i];
                rgb->b[i]=float(sum_b)/float(histogram->num_of_pixels);
            }
        }
    }
}

Dystrybuanta::~Dystrybuanta()
{
    delete [] rgb;
}

void Dystrybuanta::Draw(wxStaticBitmap *dyst_r, wxStaticBitmap *dyst_g, wxStaticBitmap *dyst_b)
{
    wxImage *bmp_r, *bmp_g, *bmp_b;
    unsigned int temp;
    if (greyscale)
    {
        if (dyst_r!=NULL)
        {
            bmp_r=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                temp=rgb->r[i]*256;
                for (unsigned int j=0;j<temp;++j)
                {
                    bmp_r->SetRGB(i,255-j,175,175,175);
                }
            }
            dyst_r->SetBitmap(*bmp_r);
        }
    }
    else
    {
        if (dyst_r!=NULL)
        {
            bmp_r=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                temp=rgb->r[i]*256;
                for (unsigned int j=0;j<temp;++j)
                {
                    bmp_r->SetRGB(i,255-j,255,0,0);
                }
            }
            dyst_r->SetBitmap(*bmp_r);
        }
        if (dyst_g!=NULL)
        {
            bmp_g=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                temp=rgb->g[i]*256;
                for (unsigned int j=0;j<temp;++j)
                {
                    bmp_g->SetRGB(i,255-j,0,255,0);
                }
            }
            dyst_g->SetBitmap(*bmp_g);
        }
        if (dyst_b!=NULL)
        {
            bmp_b=new wxImage(256,256);
            for (int i=0;i<256;++i)
            {
                temp=rgb->b[i]*256;
                for (unsigned int j=0;j<temp;++j)
                {
                    bmp_b->SetRGB(i,255-j,0,0,255);
                }
            }
            dyst_b->SetBitmap(*bmp_b);
        }
    }

}

LUT::LUT(Dystrybuanta *dyst, char method)
{
    int i=0, niezer_r=-1, niezer_g=-1, niezer_b=-1;
    if (dyst->greyscale)
    {
        for (i=0;i<256;++i)
        {
            if (niezer_r<0 && dyst->rgb->r[i]>0)
                niezer_r=i;
        }
        rgb=new data<unsigned char>;

        for (int i=niezer_r;i<256;++i)
        {
            rgb->r[i]=((dyst->rgb->r[i]-dyst->rgb->r[niezer_r])/(1-dyst->rgb->r[niezer_r]))*double(255);
        }
    }
    else
    {
        for (i=0;i<256;++i)
        {
            if (niezer_r<0 && dyst->rgb->r[i]>0)
                niezer_r=i;

            if (niezer_g<0 && dyst->rgb->g[i]>0)
                niezer_g=i;

            if (niezer_b<0 && dyst->rgb->b[i]>0)
                niezer_b=i;

        }

        int start=-1;

        rgb=new data<unsigned char>;
        //Znajdowanie najmniejszego sposrod niezer_r niezer_g niezer_b
        start=niezer_r;
        if (niezer_b<start)
            start=niezer_b;
        if (niezer_g<start)
            start=niezer_g;

        for (int i=start;i<256;++i)
        {
            rgb->r[i]=((dyst->rgb->r[i]-dyst->rgb->r[niezer_r])/(1-dyst->rgb->r[niezer_r]))*double(255);

            rgb->g[i]=((dyst->rgb->g[i]-dyst->rgb->g[niezer_g])/(1-dyst->rgb->g[niezer_g]))*double(255);

            rgb->b[i]=((dyst->rgb->b[i]-dyst->rgb->b[niezer_b])/(1-dyst->rgb->b[niezer_b]))*double(255);
        }
    }
}

wxImage *LUT::GetLutHistogram()
{
    if (rgb==NULL)
        return NULL;
    wxImage *temp;
    temp=new wxImage(256,256);
    for (int i=0;i<256;++i)
    {
        for (unsigned int j=0;j< rgb->r[i];++j)
        {
            temp->SetRGB(i,255-j,175,175,175);
        }
    }
    return temp;
}

IMG::IMG()
{
    histogram=NULL;
    dyst=NULL;
    lut=NULL;
}

IMG::IMG(wxString sciezka)
{
    LoadFile(sciezka);
    histogram=new Histogram(*this);
    dyst=new Dystrybuanta(histogram);
    oblicz_srednia_histogramu();
    lut=NULL;
}
IMG::IMG(unsigned long x, unsigned long y)
{
    Create(x,y,true);
    histogram=NULL;
    dyst=NULL;
    lut=NULL;
}

void IMG::DrawHistogram(wxStaticBitmap *hist_r, wxStaticBitmap *hist_g, wxStaticBitmap *hist_b)
{
    if (histogram==NULL)
    {
        histogram=new Histogram(*this);
    }
    histogram->draw_histogram(hist_r, hist_g, hist_b);
}

void IMG::DrawDystrybuanta(wxStaticBitmap *dyst_r, wxStaticBitmap *dyst_g, wxStaticBitmap *dyst_b)
{
    if (dyst==NULL)
    {
        if (histogram==NULL)
        {
            histogram=new Histogram(*this);
        }
        dyst=new Dystrybuanta(histogram);
    }
    dyst->Draw(dyst_r, dyst_g, dyst_b);
}

void IMG::CalculateLUT(char method)
{
    //fprintf(stderr,"(%s-%d)M2->",__FILE__,__LINE__);
    lut=new LUT(dyst, method);
}

IMG* IMG::Negacja()
{
    IMG * nowy=new IMG(GetWidth(), GetHeight());
    int r,g,b;
    for (int i=0;i<GetWidth();++i)
    {
        for (int j=0;j<GetHeight();++j)
        {
            r=255-GetRed(i,j);
            g=255-GetGreen(i,j);
            b=255-GetBlue(i,j);
            nowy->SetRGB(i,j,r,g,b);
        }
    }
    return nowy;
}

IMG *IMG::Progowanie()
{
    //bla bla
}

void IMG::oblicz_srednia_histogramu()
{
    int ilosc_r=0, ilosc_g=0, ilosc_b=0;
    srednia_histogramu_r=0.0;
    srednia_histogramu_g=0.0;
    srednia_histogramu_b=0.0;

    if (histogram->greyscale)
    {
        for (int i=0;i<256;++i)
        {
            ilosc_r+=int(histogram->rgb->r[i]);
            srednia_histogramu_r+=histogram->rgb->r[i]*i;

        }
        srednia_histogramu_r/=double(ilosc_r);
    }
    else
    {
        for (int i=0;i<256;++i)
        {
            ilosc_r=int(histogram->rgb->r[i]);
            srednia_histogramu_r+=ilosc_r*i+1;

            ilosc_g=int(histogram->rgb->g[i]);
            srednia_histogramu_g+=ilosc_g*i+1;

            ilosc_b=int(histogram->rgb->b[i]);
            srednia_histogramu_b+=ilosc_b*i+1;
        }
        srednia_histogramu_r/=double(ilosc_r);
        srednia_histogramu_g/=double(ilosc_g);
        srednia_histogramu_b/=double(ilosc_b);
    }

}

LUT *IMG::GetLut()
{
    return lut;
}

bool IMG::IsGreyscale()
{
    if (histogram==NULL)
        histogram=new Histogram(*this);
    return histogram->greyscale;
}

ObrazWBitach * ObrazWBitach::LZWDecompress()
{
    if (info=='S')
    {
        unsigned int wys, szer, bpp, rozmiar, rozmiar_po;

        //wys=(unsigned int)(dane[0]);
        //szer=(unsigned int)(dane[4]);
        //bpp=(unsigned int)(dane[8]);
        //rozmiar=(unsigned int)(dane[12]);
        //rozmiar_po=(unsigned int)(dane[16]);

        //fprintf(stderr,"Obraz %dx%d %x",szer,wys,bpp);
        //unsigned char *bufor=new unsigned char[obraz.size()];
        unsigned char *tab_pixeli=NULL;
        if (bpp==8)
        {
            tab_pixeli=new unsigned char[wys*szer];
            rozmiar_po_dekompresji=wys*szer;
        }
        else
        {
            tab_pixeli=new unsigned char[wys*szer*3];
            rozmiar_po_dekompresji=wys*szer*3;
        }
        if (rozmiar!=obraz.size())
        {
            cout<<"Rozmiary się nie zgadzają! "<<__FILE__<<":"<<__LINE__<<endl;
            rozmiar=obraz.size();
        }
        unsigned char *bufor=new unsigned char[rozmiar];
        for (unsigned int i=0;i<rozmiar;++i)
        {
            try
            {
                bufor[i]=obraz[i].to_ulong();
            }
            catch (...)
            {
                fprintf(stderr,"Za mało danych do dekompresji LZW @ %s:%d",__FILE__,__LINE__);
                return NULL;
            }
        }

        LZ_Uncompress(bufor,tab_pixeli,rozmiar);
        ObrazWBitach *nowy=new ObrazWBitach(NULL,rozmiar_po,wys,szer,bpp,rozmiar);
        for (int i=0;i<rozmiar_po;++i)
        {

        }

        delete [] bufor;
        delete [] tab_pixeli;
    }
    else
    {
        return NULL;
    }
    return NULL;
}

ObrazWBitach* ObrazWBitach::LZWCompress()
{
    if (info=='N')
    {
        //unsigned int wys=GetHeight(), szer=GetWidth(), bpp;
        unsigned char *tablica_pixeli=NULL;
        unsigned int rozmiar;
        if (bpp==8)
        {
            tablica_pixeli=new unsigned char[wys*szer];
            rozmiar=wys*szer;
        }
        else
        {
            tablica_pixeli=new unsigned char[wys*szer*3];
            rozmiar=wys*szer*3;
        }

        vector< bitset <8> >::iterator it=obraz.begin();
        int k=0;
        fprintf(stderr,"jest %d pikseli\n",obraz.size());
        if (rozmiar!=obraz.size())
        {
            cout<<"Ilość pikseli się nie zgadza!!"<<endl;
            rozmiar=obraz.size();
        }
        //Czemu iterator nie działa?
        for (k=0;k<rozmiar;++k);
        {

            tablica_pixeli[k]=it->to_ulong();
            it++;
            //line;
            //++k;

        }
        fprintf(stderr,"obraz %dx%d %d \nKOMPRESJA... Proszę czekać...",szer,wys,bpp);
        unsigned char *out=new unsigned char[(unsigned int)(double(double(rozmiar)*(double(257)/double(256)))+1)];
        unsigned int wyjscie_rozmiar=LZ_Compress(tablica_pixeli,out,rozmiar);
        fprintf(stderr,"zrobiono %d z %d pieli\n",wyjscie_rozmiar,rozmiar);
        //delete [] out;
        line;
        //delete [] tablica_pixeli;
        line;
        ObrazWBitach *nowy=new ObrazWBitach(out,szer, wys, bpp, wyjscie_rozmiar,rozmiar);
        line;
        return nowy;
    }
    else
        return NULL;
    return NULL;


}

template <typename T> data<T>::~data()
{
    delete [] r;
    delete [] g;
    delete [] b;
}

template <typename T>
data<T>::data(bool empty, unsigned long nsize)
{
    size=nsize;
    if (empty)
    {
        r=NULL;
        b=NULL;
        g=NULL;
    }
    else
    {
        r=new T[size];
        g=new T[size];
        b=new T[size];
        for (unsigned int i=0;i<size;++i)
        {
            r[i]=0;
            g[i]=0;
            b[i]=0;
        }
    }
}


unsigned char ObrazWBitach::GetR(int x, int y)
{
    if (x<szer && y<wys)
        return char(obraz[x*szer+y].to_ulong());
    else return char();
}
unsigned char ObrazWBitach::GetG(int x, int y)
{
    if (x<szer && y<wys && bpp>8)
    {
        return char(obraz[((x*szer)+y)+1].to_ulong());
    }
    else if (x<szer && y<wys && bpp<=8)
    {
        return char(obraz[x*szer+y].to_ulong());
    }
    else return char();
}
unsigned char ObrazWBitach::GetB(int x, int y)
{
    if (x<szer && y<wys && bpp>8)
    {
        return char(obraz[((x*szer)+y)+2].to_ulong());
    }
    else if (x<szer && y<wys && bpp<=8)
    {
        return char(obraz[x*szer+y].to_ulong());
    }
    else return char();
}
unsigned char* ObrazWBitach::GetBits(int x, int y)
{
    if (x<szer && y<wys && bpp>8)
    {
        unsigned char *wynik=new unsigned char[3];
        wynik[0]=(unsigned char)(obraz[((x*szer)+y)].to_ulong());
        wynik[1]=(unsigned char)(obraz[((x*szer)+y)+1].to_ulong());
        wynik[2]=(unsigned char)(obraz[((x*szer)+y)+2].to_ulong());
        return wynik;
    }
    else if (x<szer && y<wys && bpp<=8)
    {
        unsigned char *wynik=new unsigned char[3];
        wynik[0]=(unsigned char)(obraz[((x*szer)+y)].to_ulong());
        wynik[1]=(unsigned char)(obraz[((x*szer)+y)].to_ulong());
        wynik[2]=(unsigned char)(obraz[((x*szer)+y)].to_ulong());
        return wynik;

    }
    else return NULL;
}

ObrazWBitach::ObrazWBitach(IMG &org_obraz)
{
    unsigned int MaxX=org_obraz.GetWidth();
    unsigned int MaxY=org_obraz.GetHeight();
    if (org_obraz.IsGreyscale())
    {
        bpp=8;
        fprintf(stderr,"Obraz jest szaroodcieniowy\n");
        for (unsigned int y=0;y<MaxY;++y)
        {
            for (unsigned int x=0;x<MaxX;++x)
            {
                obraz.push_back(bitset <8> (org_obraz.GetRed(x,y)));
            }
        }
    }
    else
    {
        bpp=24;
        fprintf(stderr,"Obraz NIE jest szaroodcieniowy\n");
        for (unsigned int y=0;y<MaxY;++y)
        {
            for (unsigned int x=0;x<MaxX;++x)
            {
                obraz.push_back(bitset <8> (org_obraz.GetRed(x,y)));
                obraz.push_back(bitset <8> (org_obraz.GetGreen(x,y)));
                obraz.push_back(bitset <8> (org_obraz.GetBlue(x,y)));
            }
        }
    }
    wys=MaxY;
    szer=MaxX;
    rozmiar=wys*szer*(bpp/8);
    rozmiar_po_dekompresji=rozmiar;

}

IMG *ObrazWBitach::GetIMG()
{
    IMG *new_obraz=new IMG(szer,wys);
    vector< bitset<8> >::iterator it=obraz.begin();
    unsigned char r,g,b;

    for (int y=0;y<wys;++y)
    {
        for (int x=0;x<szer;++x)
        {
            if (bpp>8)
            {
                r=(unsigned char)(it->to_ulong());
                it++;
                g=(unsigned char)(it->to_ulong());
                it++;
                b=(unsigned char)(it->to_ulong());
                it++;
                new_obraz->SetRGB(x,y,r,g,b);
            }
            else
            {
                r=(unsigned char)(it->to_ulong());
                it++;
                new_obraz->SetRGB(x,y,r,r,r);
            }
        }
    }
    return new_obraz;

}

void ObrazWBitach::Ukryj(ObrazWBitach &ukrywany, int ile)
{
    char strdeb[256];
    sprintf(strdeb,"Obraz ukrywany %dx%d ukrywam na %d bitach w obrazie %dx%d",ukrywany.szer,ukrywany.wys,ile,szer,wys);
    info(strdeb);
    int max_rozmiar=(wys*szer*(bpp/8)*ile);
    if (ile>0 || ile < 8)
    {
        sprintf(strdeb,"%d*%d*(%d/8)=%d < %d?",wys,szer,bpp,max_rozmiar,ukrywany.rozmiar*8);
        info(strdeb);
        if (max_rozmiar<ukrywany.rozmiar*8)
        {
            cout<<"Za mały"<<endl;
            wxString errinfo;
            errinfo<<_("Obraz ukrywający jest za mały! Największy możliwy obraz do ukrycia może mieć ");

            if ((max_rozmiar-1)>8)
            {
                if (max_rozmiar-1>8*1024)
                {
                    errinfo<<long(((max_rozmiar-1)/8)/1024);
                    errinfo<<_(" kilobajtów. Aktualnie ukrywany obraz jest o ");
                }
                else
                {
                    errinfo<<long((max_rozmiar-1)/8);
                    errinfo<<_(" bajtów. Aktualnie ukrywany obraz jest o ");
                }
            }
            else
            {
                errinfo<<max_rozmiar-1;
                errinfo<<_(" bitów. Aktualnie ukrywany obraz jest o ");
            }
            long brakujace_miejsce=ukrywany.rozmiar_po_dekompresji*8-((wys*szer*(bpp/8)*ile)-1);
            if (brakujace_miejsce>8)
            {
                if (brakujace_miejsce>8*1024)
                {
                    errinfo<<(brakujace_miejsce/(8*1024));
                    errinfo<<_(" kilobajtów za duży. Zmniejsz go albo przeznacz więcej bitów na ukrycie.");
                }
                else
                {
                    errinfo<< brakujace_miejsce/8;
                    errinfo<<_(" bajtów za duży. Zmniejsz go albo przeznacz więcej bitów na ukrycie.");
                }
            }
            else
            {
                errinfo<<brakujace_miejsce;
                errinfo<<_(" bitów za duży. Zmniejsz go albo przeznacz więcej bitów na ukrycie.");
            }
            throw(errinfo);
        }
        vector < bitset<8> >::iterator it_ukrywany=ukrywany.obraz.begin();
        vector < bitset<8> >::iterator it_ukrywajacy=obraz.begin();
        bitset < 4 > ile_bitow(ile);

        it_ukrywajacy->set(0,ile_bitow[0]);
        it_ukrywajacy->set(1,ile_bitow[1]);
        it_ukrywajacy++;
        it_ukrywajacy->set(0,ile_bitow[2]);
        it_ukrywajacy->set(1,ile_bitow[3]);
        it_ukrywajacy++;

        bitset<sizeof(char)*8> bit_info(ukrywany.info);
        bitset<sizeof(int)*8> bit_wys(ukrywany.wys);
        bitset<sizeof(int)*8> bit_szer(ukrywany.szer);
        bitset<sizeof(int)*8> bit_bpp(ukrywany.bpp);
        bitset<sizeof(int)*8> bit_rozmiar(ukrywany.rozmiar);
        bitset<sizeof(int)*8> bit_rozmiar_po(ukrywany.rozmiar_po_dekompresji);

        int ktory_bit=0;

        for (int i=0;i<sizeof(char)*8;++i)
        {
            it_ukrywajacy->set(ktory_bit%ile,bit_info[i]);
            ktory_bit++;
            if (ktory_bit>=ile)
            {
                ktory_bit=0;
                it_ukrywajacy++;
            }
        }
        for (int i=0;i<sizeof(int)*8;++i)
        {
            it_ukrywajacy->set(ktory_bit%ile,bit_wys[i]);
            ktory_bit++;
            if (ktory_bit>=ile)
            {
                ktory_bit=0;
                it_ukrywajacy++;
            }
        }

        for (int i=0;i<sizeof(int)*8;++i)
        {
            it_ukrywajacy->set(ktory_bit%ile,bit_szer[i]);
            ktory_bit++;
            if (ktory_bit>=ile)
            {
                ktory_bit=0;
                it_ukrywajacy++;
            }
        }

        for (int i=0;i<sizeof(int)*8;++i)
        {
            it_ukrywajacy->set(ktory_bit%ile,bit_bpp[i]);
            ktory_bit++;
            if (ktory_bit>=ile)
            {
                ktory_bit=0;
                it_ukrywajacy++;
            }
        }

        for (int i=0;i<sizeof(int)*8;++i)
        {
            it_ukrywajacy->set(ktory_bit%ile,bit_rozmiar[i]);
            ktory_bit++;
            if (ktory_bit>=ile)
            {
                ktory_bit=0;
                it_ukrywajacy++;
            }
        }

        for (int i=0;i<sizeof(int)*8;++i)
        {
            it_ukrywajacy->set(ktory_bit%ile,bit_rozmiar_po[i]);
            ktory_bit++;
            if (ktory_bit>=ile)
            {
                ktory_bit=0;
                it_ukrywajacy++;
            }
        }

        line;
        bitset<8> tmp=*it_ukrywany;
        while (it_ukrywany!=ukrywany.obraz.end() && it_ukrywajacy!=obraz.end())
        {

            for (unsigned int i=0;i<8;++i)
            {
                if (ktory_bit>=ile)
                {
                    ktory_bit=0;
                    it_ukrywajacy++;
                }
                it_ukrywajacy->set(ktory_bit,tmp[i]);
                ++ktory_bit;
            }
            it_ukrywany++;
            tmp=*it_ukrywany;
        }
        line;

    }
    info("Koniec Ukrywanie");
}

ObrazWBitach* ObrazWBitach::Odkryj()
{
    //Zmienne pomocnicze
    int nwys=0,nszer=0,nbpp=0,nrozmiar=0,nrozmiar_po=0;
    char ninfo;
    bitset <8> ile;
    vector < bitset<8> >::iterator it=obraz.begin();
    ile=0;
    //Odczyt nagłówka
    bitset<8> tmp=*it;
    ile.set(0,tmp[0]);
    ile.set(1,tmp[1]);
    it++;
    tmp=*it;

    ile.set(2,tmp[0]);
    ile.set(3,tmp[1]);

    it++;
    tmp=*it;

    char debug[256];
    /*sprintf(debug,"it=%s czyli %d, tmp=%s czyli %d",it->to_string().c_str(), it->to_ulong(),
            tmp.to_string().c_str(), tmp.to_ulong());
    info(debug);*/

    int ile_int=ile.to_ulong();

    bitset<sizeof(char)*8> bit_info;

    bitset<sizeof(int)*8> dane[5];

    int bit=0;
    //Wydobywam informacje czy plik skompresowany
    for (int n=0;n<sizeof(char)*8;++n)
    {
        if (bit>=ile_int)
        {
            bit=0;
            it++;
            tmp=*it;

            /*sprintf(debug,"it=%s czyli %d, tmp=%s czyli %d",it->to_string().c_str(), it->to_ulong(),
                    tmp.to_string().c_str(), tmp.to_ulong());
            info(debug);*/
        }
        bit_info.set(n,tmp[bit]);
        ++bit;
    }


    //Wydobywam informacje o pliku
    for (int i=0;i<5;++i)
    {
        for (int n=0;n<sizeof(int)*8;++n)
        {
            if (bit>=ile_int)
            {
                bit=0;
                it++;
                tmp=*it;

                /*sprintf(debug,"it=%s czyli %d, tmp=%s czyli %d",it->to_string().c_str(), it->to_ulong(),
                        tmp.to_string().c_str(), tmp.to_ulong());
                info(debug);*/
            }
            dane[i].set(n,tmp[bit]);
            ++bit;
        }
    }
    /*sprintf(debug,"dane[0]=%s czyli %d, dane[1]=%s czyli %d",dane[0].to_string().c_str(), dane[0].to_ulong(),
            dane[1].to_string().c_str(), dane[1].to_ulong());
    info(debug);*/
    ninfo=char(bit_info.to_ulong());
    nwys=dane[0].to_ulong();
    nszer=dane[1].to_ulong();
    nbpp=dane[2].to_ulong();
    nrozmiar=dane[3].to_ulong();
    nrozmiar_po=dane[4].to_ulong();

    cout<<"Obraz wydobywany: Szerokosc: "<<nszer<<" wysokosc: "<<nwys<<" bpp: "<<nbpp<<" rozmiar: "<<nrozmiar<<" rozmiar po dekompresji: "<<nrozmiar_po<<endl;
    ObrazWBitach* nowy=new ObrazWBitach(NULL, nszer, nwys, nbpp, nrozmiar,nrozmiar_po);
    nowy->info=ninfo;
    line;
    int piksele=0;
    for (int i=0;i<nrozmiar_po;++i)
    {
        bitset<8> dana;
        for (int n=0;n<8;++n)
        {
            if (bit>=ile_int)
            {
                bit=0;
                it++;
                tmp=*it;
            }
            dana.set(n,tmp[bit]);
            ++bit;
        }
        //cout<<"dodaje "<<dana<<endl;
        nowy->obraz.push_back(dana);
        piksele++;
        /*sprintf(debug,"i=%d, rozmiar_po=%d",i,rozmiar_po);
        info(debug);*/
    }
    //cout<<"Pixeli="<<piksele<<endl;
    line;
    return nowy;
}

ObrazWBitach::ObrazWBitach(unsigned char *ndane, int nszer, int nwys, int nbpp, int nrozmiar,int nrozmiar_po)
{
    rozmiar=nrozmiar;
    wys=nwys;
    szer=nszer;
    bpp=nbpp;
    info='N';
    rozmiar_po_dekompresji=nrozmiar_po;
    if (ndane==NULL)
        return;
    for (int i=0;i<rozmiar;++i)
    {
        obraz.push_back(bitset<8>(ndane[i]));
    }
}

ObrazWBitach::~ObrazWBitach()
{
    line;
    obraz.clear();
    line;

}

