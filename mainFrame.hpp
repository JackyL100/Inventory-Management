#include <wx/wx.h>
#include <wx/srchctrl.h>
#include <wx/splitter.h>
#include <wx/listctrl.h>
#include "customWidgets/NewItemDialog.hpp"
#include "customWidgets/SearchPanel.hpp"

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    wxMenu *menuFile;
    wxMenu *menuHelp;
    wxMenuBar *menuBar;
    wxSplitterWindow* frameSplitter;
    SearchPanel* searchPanel;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnTextEntered(wxCommandEvent& event);
    void Search(wxCommandEvent& event);
    void CreateNewItem(wxCommandEvent& event);
};
enum
{
    ID_Hello = 1,
    ID_NewItem = 2
};