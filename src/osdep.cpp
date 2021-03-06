/////////////////////////////////////////////////////////////////////////////
//###########################################################################
//## PacWars 2
//## 
//## desc.:   OS dependent code
//## author:  Antonin Hildebrand
//##          Alexander Pipelka (UNIX implementation)
//## 
//## started: 9.4.2000
//## revised: 2.3.2001
//## 
//###########################################################################

#include <string.h>
#include "osdep.h"

//###########################################################################
//## WIN implementation
//###########################################################################

#ifdef _WIN32

fhandle_t pacFindFirst(char *filespec, fileinfo_t * fileinfo)
{
	struct _finddata_t winfi;
	fhandle_t h;
	h.handle = _findfirst(filespec, &winfi);
	strcpy(fileinfo->name, winfi.name);
	return h;
}

int pacFindNext(fhandle_t handle, fileinfo_t * fileinfo)
{
	struct _finddata_t winfi;
	long res = _findnext(handle.handle, &winfi);
	strcpy(fileinfo->name, winfi.name);
	return res;
}

int pacFindClose(fhandle_t handle)
{
	return _findclose(handle.handle);
}

#else
#ifdef __BEOS__

#include "osdep_beos.cpp"

#else

//###########################################################################
//## UNIX (GNU) implementation
//###########################################################################

#include <dirent.h>
#include <fnmatch.h>

static int count;
static int file_index;
static char file_pattern[256];

static int find_dummy(const struct dirent *unused)
{
	return 1;
}

fhandle_t pacFindFirst_new(char *dir, char *ext, fileinfo_t * fileinfo)
{
	struct dirent **eps = NULL;
	fhandle_t h;

	strcpy(fileinfo->dir, dir);
	if (fileinfo->dir[strlen(fileinfo->dir) - 1] == '/') {
		fileinfo->dir[strlen(fileinfo->dir) - 1] = 0;
	}

	if (ext) {
		strcpy(fileinfo->ext, ext);
		sprintf(file_pattern, "*.%s", fileinfo->ext);
	} else {
		strcpy(file_pattern, "*");
	}

	count = scandir(fileinfo->dir, &eps, find_dummy, alphasort);
	h.handle = (long) eps;
	file_index = 0;

	if (count <= 0 || eps == NULL) {
		h.handle = -1;
	} else {
		pacFindNext(h, fileinfo);
	}

	return h;
}

int pacFindNext(fhandle_t handle, fileinfo_t * fileinfo)
{
	struct dirent **eps = (struct dirent **) handle.handle;

	if (count == 0) {
		return -1;
	}

	bool found = false;

	if(file_index < count) {

		while (!found && (file_index < count)) {
			if (fnmatch(file_pattern, eps[file_index]->d_name, FNM_PATHNAME) == 0) {
				strcpy(fileinfo->name, eps[file_index]->d_name);
				file_index++;
				found = true;
			}
			else {
				file_index++;
   			}
		}
	}

	return found ? 0 : -1;
}

int pacFindClose(fhandle_t handle)
{
	free((struct dirent **) (handle.handle));
}

#endif
#endif

//###########################################################################
//## UNIX implementation
//###########################################################################
