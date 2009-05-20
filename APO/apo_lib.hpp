#ifndef APO_LIB
#define APO_LIB
#include <wx/image.h>
#include <wx/statbmp.h>
#include <wx/msgdlg.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
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

class hist
{
private:

    unsigned long *find_max();
    void scale(unsigned long max_after=255);

    //hist *scale_histogram();
    void create_histogram_table(wxImage &obraz);


public:
    data<unsigned long> *rgb;//na razie publiczne, aby zwiekszyc wydajnosc
    data<unsigned long> *rescaled_rgb;

    bool greyscale;
    unsigned long num_of_pixels;

    hist(bool empty=false);
    hist(wxImage &obraz);
    ~hist();
    void draw_histogram(wxStaticBitmap *hist_r=NULL, wxStaticBitmap *hist_g=NULL, wxStaticBitmap *hist_b=NULL);
};

class Dystrybuanta
{
public:
    data<float> *rgb;
    bool greyscale;

    Dystrybuanta(hist *histogram);
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
/*data *scale(unsigned long max_after=255);
hist *create_histogram_table(wxImage &obraz);
hist *scale_histogram(hist *histogram);*/

/*void draw_histogram(hist *histogram, wxStaticBitmap *hist_r, wxStaticBitmap *hist_g, wxStaticBitmap *hist_b);
wxImage histogram_equalisation_1(wxImage &obraz, hist *histogram=NULL);*/

class IMG: public wxImage
{
private:
    hist *histogram;
    Dystrybuanta *dyst;
    LUT *lut;
    float srednia_histogramu_r;
    float srednia_histogramu_g;
    float srednia_histogramu_b;
    void oblicz_srednia_histogramu();



    //wxImage histogram_equalisation_1(hist *histogram=NULL);

public:
    IMG();
    IMG(wxString scezka);
    IMG(unsigned long x, unsigned long y);
    hist *GetHistogram();
    Dystrybuanta *GetDystrybuanta();
    LUT *GetLut();
    void DrawHistogram(wxStaticBitmap *hist_r=NULL, wxStaticBitmap *hist_g=NULL, wxStaticBitmap *hist_b=NULL);
    void DrawDystrybuanta(wxStaticBitmap *dyst_r=NULL, wxStaticBitmap *dyst_g=NULL, wxStaticBitmap *dyst_b=NULL);
    void CalculateLUT(char method);
    IMG *HistogramEqualisation_1();
    IMG *HistogramEqualisation_2();
    IMG *HistogramEqualisation_3();
    IMG *HistogramEqualisation_wlasna();
};
#endif

