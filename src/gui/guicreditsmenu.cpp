#include "guicreditsmenu.h"
#include "gui.h"
#include "pw2.h"

/////////////////////////////////////////////////////////////////////////////
// Credits menu widgets
/////////////////////////////////////////////////////////////////////////////

GUI_CreditsMenu::GUI_CreditsMenu() : GUI_BaseMenu(GUI_CREDITS, PG_Rect(CM_PX,CM_PY,CM_VX,CM_VY)) {

	bOK = new GUI_ButtonSmall(this, 1, PG_Rect(155,390,150,25), "COOL");
	
	mBack1 = new GUI_Bitmap(this, PG_Rect(1, 1, credits->w, credits->h), false, credits),
	CreditsMenu = new GUI_LabelC(mBack1, PG_Rect(1,4,CM_VX-2,25), "Credits", false);
	lLine[0] = new GUI_LabelC(mBack1, PG_Rect(CM_G1_PX,CM_G1_PY+35, CM_G1_VX-2,20), "Code by Antonin Hildebrand aka Woid", false);
	lLine[1] = new GUI_LabelC(mBack1, PG_Rect(CM_G1_PX,CM_G1_PY+55, CM_G1_VX-2,20), "Graphics by Petr Stastny aka Raist", false);
	lLine[2] = new GUI_LabelC(mBack1, PG_Rect(CM_G1_PX,CM_G1_PY+75, CM_G1_VX-2,20), "Music by Ondrej Broukal aka GameOver", false);
	lLine[3] = new GUI_LabelC(mBack1, PG_Rect(CM_G1X_PX,CM_G1_PY+95, CM_G1_VX-50,20), "Petr Stastny aka Raist", false);
	lLine[4] = new GUI_LabelC(mBack1, PG_Rect(CM_G1X_PX,CM_G1_PY+115, CM_G1_VX-50,20), "Pavel Mirejovsky aka Dusty", false);
	lLine[6] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+155, CM_G2_VX-2,20), "PG_ library by Sam Latinga", false);
	lLine[7] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+175, CM_G2_VX-2,20), "SeeR scripting engine", false);
	lLine[5] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+195, CM_G2_VX-2,20), "by Przemek Podsiadly aka Theur", false);
	lLine[8] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+215, CM_G2_VX-2,20), "BASS sound system by Ian Luck", false);
	lLine[9] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+235, CM_G2_VX-2,20), "Mappy by Robin Burrows", false);
	lLine[10] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+255, CM_G2_VX-2,20), "ParaGUI by Alexander Pipelka", false);
	lLine[11] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+275, CM_G2_VX-2,20), "ImageMagick library by ImageMagick Studio", false);
	lLine[12] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+295, CM_G2_VX-2,20), "PG_: net, console, ttf, mixer and image libs", false);
	lLine[13] = new GUI_LabelC(mBack1, PG_Rect(CM_G2_PX,CM_G2_PY+315, CM_G2_VX-2,20), "zlib, libpng, libjpeg, UPX packer", false);
	lLine[14] = new GUI_LabelC(mBack1, PG_Rect(CM_G1_PX,CM_G1_PY+135, CM_G1_VX-2,20), "Linux port by Alexander Pipelka aka Braindead", false);
	lLine[15] = new GUI_LabelC(mBack1, PG_Rect(4,235, CM_VX-2,20), "Thanks to SLiK, Mem, Lada, Tessien, Farey, Kerim, Garett Banuk, Nula, ...", false);
	lLine[17] = new GUI_LabelC(mBack1, PG_Rect(4,315, CM_VX-2,25), "visit PW2 site at", false);
	lLine[16] = new GUI_LabelC(mBack1, PG_Rect(CM_G1_PX,CM_G1_PY+175, CM_G1_VX-2,20), "Iain Syme author of the orignal PacWars", false);
	lLine[18] = new GUI_LabelC(mBack1, PG_Rect(4,345, CM_VX-2,25), "http://pw2.tsx.org", false);

	Default();

	CreditsMenu->SetAlignment(PG_TA_CENTER);
	CreditsMenu->SetFont(MainFont);

	for(int i=0; i<19; i++) lLine[i]->SetAlignment(PG_TA_LEFT);

	lLine[17]->SetAlignment(PG_TA_CENTER);
	lLine[17]->SetFont(MainFont);
	lLine[18]->SetFont(MainFont);
	lLine[18]->SetAlignment(PG_TA_CENTER);
	lLine[15]->SetAlignment(PG_TA_CENTER);
}

void GUI_CreditsMenu::Default() {
}

bool GUI_CreditsMenu::eventButtonClick(int id, PG_Widget* widget) {

	switch (id) {
	case 1:
		Return();
		break;
	}
	
	return true;
}

void GUI_CreditsMenu::eventShow() {
  Clear();
}

void GUI_CreditsMenu::eventHide() {
}

