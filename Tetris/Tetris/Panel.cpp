#include "StdAfx.h"
#include "Panel.h"
// Applying the flicker free panel.
CPanel::CPanel(void)  : Panel()
{
	this->DoubleBuffered = true;
}
