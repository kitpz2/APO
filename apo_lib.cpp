#include "apo_lib.hpp"
#include <iostream>
using namespace std;

unsigned long* hist::find_max()
{
    unsigned long *max=new unsigned long[3];//0-r 1-g 2-b
    max[0]=max[1]=max[2]=0;
    greyscale=true;
    for (int i=0;i<rgb->size;++i)
    {
        if (rgb->r[i]>max[0])
            max[0]=rgb->r[i];

        if (rgb->g[i]>max[1])
            max[1]=rgb->g[i];

        if (rgb->b[i]>max[2])
            max[2]=rgb->b[i];

        if (rgb->r[i]!=rgb->g[i] || rgb->g[i]!=rgb->b[i])
            greyscale=false;
    }
    return max;
}

void hist::scale(unsigned long max_after)
{
    unsigned long *max_before=find_max();
    rescaled_rgb=new data<unsigned long>(false, rgb->size);
    if (greyscale)
    {
        for (int i=0;i<rgb->size;++i)
        {
            rescaled_rgb->r[i]=(double(rgb->r[i])/double(max_before[0]))*max_after;
        }
    }
    else
    {
        for (int i=0;i<rgb->size;++i)
        {
            rescaled_rgb->r[i]=(double(rgb->r[i])/double(max_before[0]))*max_after;

            rescaled_rgb->g[i]=(double(rgb->g[i])/double(max_before[1]))*max_after;

            rescaled_rgb->b[i]=(double(rgb->b[i])/double(max_before[2]))*max_after;
            /*rescaled_rgb->r[i]=(double(rgb->r[i])/double(num_of_pixels))*max_after;

            rescaled_rgb->g[i]=(double(rgb->g[i])/double(num_of_pixels))*max_after;

            rescaled_rgb->b[i]=(double(rgb->b[i])/double(num_of_pixels))*max_after;*/
        }
    }
}
/*void clean(unsigned long tab[], int elements, unsigned int init_value)
{
    for (int i=0;i<elements;++i)
    {
        tab[i]=init_value;
    }
}*/

void hist::create_histogram_table(wxImage &obraz)
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

/*hist *scale_histogram(hist *histogram)
{
    hist *temp=new hist(true);
    unsigned long max_r=find_max(histogram->r,256);
    unsigned long max_g=find_max(histogram->g,256);
    unsigned long max_b=find_max(histogram->b,256);
    temp->r=scale(histogram->r, 256, max_r);
    temp->g=scale(histogram->g, 256, max_g);
    temp->b=scale(histogram->b, 256, max_b);
    return temp;
}*/

void hist::draw_histogram(wxStaticBitmap *hist_r, wxStaticBitmap *hist_g, wxStaticBitmap *hist_b)
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
/*wxImage histogram_equalisation_1(wxImage &obraz, hist *histogram)
{
    if (histogram==NULL)
    {
        histogram=create_histogram_table(obraz);
    }

}*/

hist::hist(bool empty)
{
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

hist::hist(wxImage &obraz)
{
    rgb=new data<unsigned long>(false,256);
    num_of_pixels=0;
    create_histogram_table(obraz);
}

Dystrybuanta::Dystrybuanta(hist *histogram)
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

void Dystrybuanta::Draw(wxStaticBitmap *dyst_r, wxStaticBitmap *dyst_g, wxStaticBitmap *dyst_b)
{
    wxImage *bmp_r, *bmp_g, *bmp_b;
    int temp;
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

hist::~hist()
{
    delete [] rgb;
    delete [] rescaled_rgb;
}

LUT::LUT(Dystrybuanta *dyst, char method)
{
    int i=0, niezer_r=-1, niezer_g=-1, niezer_b=-1;
    if (dyst->greyscale)
    {
        for (i=0;i<256;++i)
        {
            if (dyst->rgb->r[i]>0)
            {
                niezer_r=i;
                break;
            }
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
        int start=-1;;
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

IMG::IMG(wxString sciezka)
{
    LoadFile(sciezka);
    histogram=new hist(*this);
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
        histogram=new hist(*this);
    }
    histogram->draw_histogram(hist_r, hist_g, hist_b);
}

void IMG::DrawDystrybuanta(wxStaticBitmap *dyst_r, wxStaticBitmap *dyst_g, wxStaticBitmap *dyst_b)
{
    if (dyst==NULL)
    {
        if (histogram==NULL)
        {
            histogram=new hist(*this);
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
IMG* IMG::HistogramEqualisation_1()
{
    IMG *nowy=new IMG(GetWidth(), GetHeight());

    int R=0;
    int Hint=0;
    int left[256];
    int right[256];
    int new_r[256];
    for (int Z=0;Z<256;++Z)
    {

        left[Z]=R;
        Hint+=int(histogram->rgb->r[Z]);
        while (Hint>srednia_histogramu_r)
        {
            Hint-=srednia_histogramu_r;
            ++R;
        }
        right[Z]=R;

        new_r[Z]=(double(left[Z]+right[Z]))/2.0;
    }

    int max_left, max_right, max_new_r;
    max_left=*max_element(left,left+256);
    max_right=*max_element(right,right+256);
    max_new_r=*max_element(new_r,new_r+256);
    if (max_left>255 || max_right>255 || max_new_r>255)
    {
        for (int i=0;i<256;++i)
        {
            left[i]=(double(left[i])/double(max_left))*double(255);
            right[i]=(double(right[i])/double(max_right))*double(255);
            new_r[i]=(double(new_r[i])/double(max_new_r))*double(255);
        }
    }

    int temp_r;
    for (int i=0;i<GetWidth();++i)
    {
        for (int j=0;j<GetHeight();++j)
        {
            temp_r=GetRed(i,j);
            if (left[temp_r]==right[temp_r])
                nowy->SetRGB(i,j,left[temp_r],left[temp_r],left[temp_r]);
            else
                nowy->SetRGB(i,j,new_r[temp_r],new_r[temp_r],new_r[temp_r]);
        }
    }

    return nowy;

}

IMG* IMG::HistogramEqualisation_2()
{

    IMG *nowy=new IMG(GetWidth(), GetHeight());

    int R=0;
    int Hint=0;
    int left[256];
    int right[256];
    int new_r[256];
    for (int Z=0;Z<256;++Z)
    {
        left[Z]=R;
        Hint+=int(histogram->rgb->r[Z]);
        while (Hint>srednia_histogramu_r)
        {
            Hint-=srednia_histogramu_r;
            ++R;
        }
        right[Z]=R;

    }

    int max_left, max_right, max_new_r;
    max_left=*max_element(left,left+256);
    max_right=*max_element(right,right+256);
    //max_new_r=*max_element(new_r,new_r+256);
    if (max_left>255 || max_right>255 )
    {
        for (int i=0;i<256;++i)
        {
            left[i]=(double(left[i])/double(max_left))*double(255);
            right[i]=(double(right[i])/double(max_right))*double(255);
            //new_r[i]=(double(new_r[i])/double(max_new_r))*double(255);
        }
    }

    for (int i=0;i<256;++i)
    {
        new_r[i]=right[i]-left[i];
    }

    int temp_r;

    srand(time(NULL));

    for (int i=0;i<GetWidth();++i)
    {
        for (int j=0;j<GetHeight();++j)
        {
            temp_r=GetRed(i,j);
            if (left[temp_r]==right[temp_r])
                nowy->SetRGB(i,j,left[temp_r],left[temp_r],left[temp_r]);
            else
            {
                temp_r=(rand()%(new_r[temp_r]+1))+left[temp_r];
                nowy->SetRGB(i,j,temp_r,temp_r,temp_r);
            }
        }
    }

    return nowy;
}

IMG* IMG::HistogramEqualisation_3()
{

    IMG *nowy=new IMG(GetWidth(), GetHeight());

    int R=0;
    int Hint=0;
    int left[256];
    int right[256];
    for (int Z=0;Z<256;++Z)
    {
        left[Z]=R;
        Hint+=int(histogram->rgb->r[Z]);
        while (Hint>srednia_histogramu_r)
        {
            Hint-=srednia_histogramu_r;
            ++R;
        }
        right[Z]=R;
    }

    int max_left, max_right;
    max_left=*max_element(left,left+256);
    max_right=*max_element(right,right+256);
    if (max_left>255 || max_right>255)
    {
        for (int i=0;i<256;++i)
        {
            left[i]=(double(left[i])/double(max_left))*double(255);
            right[i]=(double(right[i])/double(max_right))*double(255);
        }
    }

    int temp_r;

    srand(time(NULL));


    float srednia=0.0;
    int gl, gs, gp, sl, ss, sp, dl, ds, dp;
    int ile;
    for (int i=0;i<GetWidth();++i)
    {
        for (int j=0;j<GetHeight();++j)
        {
            temp_r=GetRed(i,j);
            if (left[temp_r]==right[temp_r])
                nowy->SetRGB(i,j,left[temp_r],left[temp_r],left[temp_r]);
            else
            {

                gl=gs=gp=sl=ss=sp=dl=ds=dp=-1;
                ile=0;
                if (i==0)
                {
                    gl=0;
                    sl=0;
                    dl=0;
                }
                if (i==GetWidth()-1)
                {
                    gp=0;
                    sp=0;
                    sp=0;
                }
                if (j==0)
                {
                    gp=0;
                    gs=0;
                    gp=0;
                }
                if (j==GetHeight()-1)
                {
                    dl=0;
                    ds=0;
                    dp=0;
                }
                if (gl==-1)
                {
                    gl=GetRed(i-1,j-1);
                    ++ile;
                }
                if (gs==-1)
                {
                    gs=GetRed(i,j-1);
                    ++ile;
                }
                if (gp==-1)
                {
                    gp=GetRed(i+1,j-1);
                    ++ile;
                }
                if (sl==-1)
                {
                    sl=GetRed(i-1,j);
                    ++ile;
                }
                if (ss==-1)
                {
                    ss=GetRed(i,j);
                    ++ile;
                }
                if (sp==-1)
                {
                    sp=GetRed(i+1,j);
                    ++ile;
                }
                if (dl==-1)
                {
                    dl=GetRed(i-1,j+1);
                    ++ile;
                }
                if (ds==-1)
                {
                    ds=GetRed(i,j+1);
                    ++ile;
                }
                if (dp==-1)
                {
                    dp=GetRed(i+1,j+1);
                    ++ile;
                }
                srednia=(double(gl+gs+gp+sl+ss+sp+dl+ds+dp))/double(ile);
                if (srednia>right[temp_r])
                {
                    nowy->SetRGB(i,j,right[temp_r],right[temp_r],right[temp_r]);
                }
                else if (srednia<left[temp_r])
                {
                    nowy->SetRGB(i,j,left[temp_r],left[temp_r],left[temp_r]);
                }
                else
                {
                    nowy->SetRGB(i,j,srednia,srednia,srednia);
                }

                //temp_r=(rand()%(new_r[temp_r]+1))+left[temp_r];
            }
            nowy->SetRGB(i,j,temp_r,temp_r,temp_r);
        }
    }

    return nowy;
}

IMG* IMG::HistogramEqualisation_wlasna()
{
    if (lut==NULL)
    {
        CalculateLUT(4);
    }
    else
    {
        delete lut;
        CalculateLUT(4);
    }
    IMG *nowy=new IMG(GetWidth(), GetHeight());
    if (histogram->greyscale)
    {
        for (int i=0;i<GetWidth();++i)
        {
            for (int j=0;j<GetHeight();++j)
            {
                nowy->SetRGB(i,j,
                             lut->rgb->r[int(GetRed(i,j))],
                             lut->rgb->r[int(GetRed(i,j))],
                             lut->rgb->r[int(GetRed(i,j))]);
            }
        }
    }
    else
    {
        for (int i=0;i<GetWidth();++i)
        {
            for (int j=0;j<GetHeight();++j)
            {
                nowy->SetRGB(i,j,
                             lut->rgb->r[int(GetRed(i,j))],
                             lut->rgb->g[int(GetGreen(i,j))],
                             lut->rgb->b[int(GetBlue(i,j))]);
            }
        }
    }
    return nowy;
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

IMG* IMG::FiltracjaGoroprzepustowa(int *nmaska, bool wyostrzanie)
{
    int maska[3][3];

    int norm=0;
    int k=0;
    for (int i=0;i<3;++i)
    {
        for (int j=0;j<3;++j)
        {

            maska[i][j]=nmaska[k];
            norm+=maska[i][j];
            ++k;
            cout<<maska[i][j];
        }
        cout<<endl;
    }
    IMG *nowy=new IMG(GetWidth(), GetHeight());//Stworzenie obrazu do którego zapiszemy wynik
    int r,g,b, tempr, tempg, tempb, maxr=0, maxg=0, maxb=0;//Zmienne pomocnicze
    if(histogram==NULL)
        histogram=new hist(*this);
    if (histogram->greyscale)//Czy obraz jest czarnobiały?
    {
        int **obraz=new int*[GetWidth()];//Tworzymy tablice przechowującą tymczasowo pixele
        for (int i=0;i<GetWidth();++i)//Lecimy po obrazie
        {
            obraz[i]=new int[GetHeight()];
            for (int j=0;j<GetHeight();++j)//Pixel po pixelu
            {
                if (i!=0 && i!=GetWidth()-1 && j!=0 && j!=GetHeight()-1)//Jeżeli nie jesteśmy na krawędzi obrazu
                {
                    //Zastosowanie maski
                    obraz[i][j]=(GetRed(i-1,j-1)*maska[0][0])+(GetRed(i,j-1)*maska[1][0])+(GetRed(i+1,j-1)*maska[2][0])+
                                (GetRed(i-1,j)*maska[0][1])+(GetRed(i,j)*maska[1][1])+(GetRed(i+1,j)*maska[2][1])+
                                (GetRed(i-1,j+1)*maska[0][2])+(GetRed(i,j+1)*maska[1][2])+(GetRed(i+1,j+1)*maska[2][2]);

                    if (wyostrzanie==true)//Jeżeli robimy wyostrzanie
                    {
                        obraz[i][j]+=GetRed(i,j);//To nakladamy wykryte krawedzie na obraz oryginalny aby go wyostrzyc
                    }
                    if (obraz[i][j]<0)//Jeżeli jakiś pixel spadł poniżej zera to ustawiamy go na zero
                        obraz[i][j]=0;


                    if (obraz[i][j]>maxr)//Wyszukiwanie maxa
                        maxr=obraz[i][j];
                }
                else
                {
                    obraz[i][j]=GetRed(i,j);//Wrzucenie pixela do tymczaowej tablicy
                }
            }
        }

        for (int i=0;i<GetWidth();++i)
        {
            for (int j=0;j<GetHeight();++j)
            {
                if (i!=0 && i!=GetWidth()-1 && j!=0 && j!=GetHeight()-1)
                {
                    obraz[i][j]= int(double(obraz[i][j]) / double(maxr) * 255);//Ustawiamy pixele w obrazie
                    nowy->SetRGB(i,j,obraz[i][j],obraz[i][j],obraz[i][j]);
                }
            }
        }
    }
    else
    {
        int **obrazr=new int*[GetWidth()];
        int **obrazg=new int*[GetWidth()];
        int **obrazb=new int*[GetWidth()];
        for (int i=0;i<GetWidth();++i)
        {
            obrazr[i]=new int[GetHeight()];
            obrazg[i]=new int[GetHeight()];
            obrazb[i]=new int[GetHeight()];
            for (int j=0;j<GetHeight();++j)
            {
                if (i!=0 && i!=GetWidth()-1 && j!=0 && j!=GetHeight()-1)
                {
                    obrazr[i][j]=(GetRed(i-1,j-1)*maska[0][0])+(GetRed(i,j-1)*maska[1][0])+(GetRed(i+1,j-1)*maska[2][0])+(GetRed(i-1,j)*maska[0][1])+(GetRed(i,j)*maska[1][1])+(GetRed(i+1,j)*maska[2][1])+(GetRed(i-1,j+1)*maska[0][2])+(GetRed(i,j+1)*maska[1][2])+(GetRed(i+1,j+1)*maska[2][2]);

                    obrazg[i][j]=(GetGreen(i-1,j-1)*maska[0][0])+(GetGreen(i,j-1)*maska[1][0])+(GetGreen(i+1,j-1)*maska[2][0])+(GetGreen(i-1,j)*maska[0][1])+(GetGreen(i,j)*maska[1][1])+(GetGreen(i+1,j)*maska[2][1])+(GetGreen(i-1,j+1)*maska[0][2])+(GetGreen(i,j+1)*maska[1][2])+(GetGreen(i+1,j+1)*maska[2][2]);
                    obrazb[i][j]=(GetBlue(i-1,j-1)*maska[0][0])+(GetBlue(i,j-1)*maska[1][0])+(GetBlue(i+1,j-1)*maska[2][0])+(GetBlue(i-1,j)*maska[0][1])+(GetBlue(i,j)*maska[1][1])+(GetBlue(i+1,j)*maska[2][1])+(GetBlue(i-1,j+1)*maska[0][2])+(GetBlue(i,j+1)*maska[1][2])+(GetBlue(i+1,j+1)*maska[2][2]);
                    if (wyostrzanie==true)
                    {
                        obrazr[i][j]+=GetRed(i,j);
                        obrazg[i][j]+=GetGreen(i,j);
                        obrazb[i][j]+=GetBlue(i,j);
                    }
                    if (obrazr[i][j]<0)
                        obrazr[i][j]=0;
                    if (obrazg[i][j]<0)
                        obrazg[i][j]=0;
                    if (obrazb[i][j]<0)
                        obrazb[i][j]=0;

                    if (obrazr[i][j]>maxr)
                    {
                        maxr=obrazr[i][j];
                    }
                    if (obrazg[i][j]>maxg)
                    {
                        maxg=obrazg[i][j];
                    }
                    if (obrazb[i][j]>maxb)
                    {
                        maxb=obrazb[i][j];
                    }
                }
                else
                {
                    obrazr[i][j]=GetRed(i,j);
                    obrazg[i][j]=GetGreen(i,j);
                    obrazb[i][j]=GetBlue(i,j);
                }
            }
        }
        for (int i=0;i<GetWidth();++i)
        {
            for (int j=0;j<GetHeight();++j)
            {
                if (i!=0 && i!=GetWidth()-1 && j!=0 && j!=GetHeight()-1)
                {
                    obrazr[i][j]= int(double(obrazr[i][j]) / double(maxr) * 255);
                    obrazg[i][j]= int(double(obrazg[i][j]) / double(maxg) * 255);
                    obrazb[i][j]= int(double(obrazb[i][j]) / double(maxb) * 255);
                    nowy->SetRGB(i,j,obrazr[i][j],obrazg[i][j],obrazb[i][j]);
                }
            }
        }
    }
    return nowy;

}

IMG *IMG::PoprawaCiaglosciLiniiBrzegowej()
{

}

LUT *IMG::GetLut()
{
    return lut;
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
        for (int i=0;i<size;++i)
        {
            r[i]=0;
            g[i]=0;
            b[i]=0;
        }
    }
}

template <typename T> data<T>::~data()
{
    delete [] r;
    delete [] g;
    delete [] b;
}

