#include <wx/wx.h>
#include "mainFrame.hpp"

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class masterClient {
    public:
        void logShipment();
        void getPrice();
        void logPurchase();
};