#include "editor.h"

void		render_editor(EDITOR *editor)
{
	if (BAR.activated && !BAR.updated)
		update_bar(editor);
	if (!WS_UPDATED)
		update_working_surface(editor);
	SDL_UpdateWindowSurface(EDITOR_WINDOW);
}