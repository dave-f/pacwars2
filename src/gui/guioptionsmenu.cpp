#include "guioptionsmenu.h"
#include "gui.h"

/////////////////////////////////////////////////////////////////////////////
// Options menu widgets
/////////////////////////////////////////////////////////////////////////////

GUI_OptionsMenu::GUI_OptionsMenu() : GUI_BaseMenu(GUI_OPTIONS, mkrect(OM_PX,OM_PY,OM_VX,OM_VY)) {

	lOptionsMenu = new GUI_ButtonBig(this,0, SDLWidget::mkrect(0,0,OM_VX,40), "Options Menu");
	bServer = new GUI_ButtonBig(this, 1, SDLWidget::mkrect(0,40,OM_VX,40), "Server");
	bClient = new GUI_ButtonBig(this, 5, SDLWidget::mkrect(0,80,OM_VX,40), "Client");
	bVideo = new GUI_ButtonBig(this, 2, SDLWidget::mkrect(0,120,OM_VX,40), "Video");
	bSound = new GUI_ButtonBig(this, 3, SDLWidget::mkrect(0,160,OM_VX,40), "Sound");
	bPaths = new GUI_ButtonBig(this, 4, SDLWidget::mkrect(0,200,OM_VX,40), "Paths");
	bBack = new GUI_ButtonBig(this, 10, SDLWidget::mkrect(0,240,OM_VX,40), "Back");

	Default();

	lOptionsMenu->enabled = false;
	lOptionsMenu->LoadThemeStyle("GUI_MenuTitle", "Button");
}

void GUI_OptionsMenu::Default(){
}

bool GUI_OptionsMenu::eventButtonClick(int id, SDLWidget* widget) {

	switch (id) {
	
	case 1:
		GUI_OpenMenu(GUI_SERVER);
		break;

	case 2:
		GUI_OpenMenu(GUI_VIDEO);
		break;
		
	case 3:
		GUI_OpenMenu(GUI_SOUND);
		break;

	case 4:
		GUI_OpenMenu(GUI_PATHS);
		break;
	
	case 5:
		GUI_OpenMenu(GUI_CLIENT);
		break;

	case 10:
		Return();
		break;
	}
	
	return true;
}

void GUI_OptionsMenu::eventShow() {
  Clear();
}

void GUI_OptionsMenu::eventHide() {
}

