#ifndef _UniqTest_UniqTest_h
#define _UniqTest_UniqTest_h

#include <CtrlLib/CtrlLib.h>
#include <Uniq/Uniq.h>

#define LAYOUTFILE <examples/UniqTest/UniqTest.lay>
#include <CtrlCore/lay.h>

class UniqTest : public WithUniqTestLayout<Upp::TopWindow>
{
public:
	UniqTest();

	// handles news app instances
	void handleInstance(const Upp::Vector<Upp::String>& v);
};

#endif
