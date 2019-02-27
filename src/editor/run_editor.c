# include "editor.h"

EDITOR_STATE	run_editor()
{
	EDITOR	editor;
	

	init_editor(&editor);
	while(editor.state == EDITOR_RUNNING)
	{
		render_editor(&editor);
		editor_parse_events(&editor);
	}
	print_sectors(&editor);
	destroy_editor(&editor);
	return (editor.state);
}