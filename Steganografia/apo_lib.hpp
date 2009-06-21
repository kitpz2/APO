#ifndef APO_LIB
#define APO_LIB
#include <wx/image.h>
#include <wx/statbmp.h>
#include <wx/msgdlg.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>


#include <wx/filedlg.h>
#include <fstream>

#include "lz.hpp"

#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filedlg.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>


#include <wx/intl.h>
//#include <wx/string.h>

#include <bitset>
#include <vector>
#include "debug.hpp"

using namespace std;
void clean(unsigned long tab[], int elements, unsigned int init_value=0);

template <typename T>
class data
{
public:
    T *r;
    T *g;
    T *b;
    unsigned long size;

    data(bool empty=false, unsigned long nsize=256);
    ~data();
};

class Histogram
{
private:

    unsigned long *find_max();
    void scale(unsigned long max_after=255);
    void create_histogram_table(wxImage &obraz);

public:
    data<unsigned long> *rgb;//na razie publiczne, aby zwiekszyc wydajnosc
    data<unsigned long> *rescaled_rgb;

    bool greyscale;
    unsigned long num_of_pixels;

    Histogram(bool empty=false);
    Histogram(wxImage &obraz);
    ~Histogram();
    void draw_histogram(wxStaticBitmap *hist_r=NULL, wxStaticBitmap *hist_g=NULL, wxStaticBitmap *hist_b=NULL);
};

class Dystrybuanta
{
public:
    data<float> *rgb;
    bool greyscale;

    Dystrybuanta(Histogram *histogram);
    ~Dystrybuanta();
    void Draw(wxStaticBitmap *dyst_r=NULL, wxStaticBitmap *dyst_g=NULL, wxStaticBitmap *dyst_b=NULL);
};

class LUT
{
public:
    data<unsigned char> *rgb;
    wxImage *GetLutHistogram();

    LUT(Dystrybuanta *dyst, char method);
};
unsigned long *find_max();

class IMG: public wxImage
{
private:
    Histogram *histogram;
    Dystrybuanta *dyst;
    LUT *lut;
    float srednia_histogramu_r;
    float srednia_histogramu_g;
    float srednia_histogramu_b;
    void oblicz_srednia_histogramu();

public:
    IMG();
    IMG(wxString scezka);
    IMG(unsigned long x, unsigned long y);

    Histogram *GetHistogram();
    Dystrybuanta *GetDystrybuanta();
    LUT *GetLut();

    void DrawHistogram(wxStaticBitmap *hist_r=NULL, wxStaticBitmap *hist_g=NULL, wxStaticBitmap *hist_b=NULL);
    void DrawDystrybuanta(wxStaticBitmap *dyst_r=NULL, wxStaticBitmap *dyst_g=NULL, wxStaticBitmap *dyst_b=NULL);
    void CalculateLUT(char method);

    IMG *Negacja();
    IMG *Progowanie();
    bool IsGreyscale();

};

class ObrazWBitach
{
public:

    vector< bitset <8> > obraz;
    int wys,szer,bpp, rozmiar, rozmiar_po_dekompresji;
    char info;
    //S - Skompresowany
    //N - Nie skompresowany


    unsigned char GetR(int x, int y);
    unsigned char GetG(int x, int y);
    unsigned char GetB(int x, int y);
    unsigned char& SetR(int x, int y, int ile, bitset<8> dane);
    unsigned char* GetBits(int x, int y);
    ObrazWBitach(unsigned char *ndane, int nszer, int nwys, int nbpp, int nrozmiar,int nrozmiar_po_dekompresji);
    ObrazWBitach(IMG &org_obraz);
    ~ObrazWBitach();
    IMG *GetIMG();

    ObrazWBitach* LZWDecompress();

    ObrazWBitach* LZWCompress();
    void Ukryj(ObrazWBitach &ukrywany, int ile);
    ObrazWBitach* Odkryj();

};

#endif

