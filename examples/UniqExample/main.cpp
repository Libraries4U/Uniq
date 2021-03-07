#include <CtrlLib/CtrlLib.h>
#include <Uniq/Uniq.h>

#define LAYOUTFILE <examples/UniqExample/UniqTest.lay>
#include <CtrlCore/lay.h>

class UniqAppWindow final : public WithUniqTestLayout<Upp::TopWindow>
{
public:
	UniqAppWindow()
	{
		CtrlLayout(*this, "Uniq Application");
	}

	// Handles news app instances.
	void handleInstance(const Upp::Vector<Upp::String>& v)
	{
		auto s = edit.Get() + "NEW INSTANCE LAUNCHED\n  Command line : '";
		for(int i = 0; i < v.GetCount(); i++)
			s += v[i] + ",";
		if(s[s.GetCount() - 1] == ',')
			s = s.Left(s.GetCount()-1);
		s += "'\n";
		
		edit <<= s;
		ProcessEvents();
	}
};

GUI_APP_MAIN
{
	Upp::Uniq uniq;
	
	// If not inside first instance, send commandline
	// to first instance and leave
	if(!uniq)
		return;
	
	UniqAppWindow app_window;

	// Setup callback handling other app's instances
	uniq.WhenInstance = callback(&app_window, &UniqAppWindow::handleInstance);
		
	app_window.Run();
}
