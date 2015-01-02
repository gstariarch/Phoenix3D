// PX2UIPaintManager.hpp

#ifndef PX2UIPAINTMANAGER_HPP
#define PX2UIPAINTMANAGER_HPP

#include "PX2Singleton.hpp"

namespace PX2
{

	typedef enum
	{
		UICOLOR__FIRST = 0,
		UICOLOR_WINDOW_BACKGROUND,
		UICOLOR_WINDOW_TEXT,
		UICOLOR_DIALOG_BACKGROUND,
		UICOLOR_DIALOG_TEXT_NORMAL,
		UICOLOR_DIALOG_TEXT_DARK,
		UICOLOR_MENU_BACKGROUND,
		UICOLOR_MENU_TEXT_NORMAL,
		UICOLOR_MENU_TEXT_HOVER,
		UICOLOR_MENU_TEXT_SELECTED,
		UICOLOR_TEXTCOLOR_NORMAL,
		UICOLOR_TEXTCOLOR_HOVER,
		UICOLOR_TAB_BACKGROUND_NORMAL,
		UICOLOR_TAB_BACKGROUND_SELECTED,
		UICOLOR_TAB_FOLDER_NORMAL,
		UICOLOR_TAB_FOLDER_SELECTED,
		UICOLOR_TAB_BORDER,
		UICOLOR_TAB_TEXT_NORMAL,
		UICOLOR_TAB_TEXT_SELECTED,
		UICOLOR_TAB_TEXT_DISABLED,
		UICOLOR_NAVIGATOR_BACKGROUND,
		UICOLOR_NAVIGATOR_BUTTON_HOVER,
		UICOLOR_NAVIGATOR_BUTTON_PUSHED,
		UICOLOR_NAVIGATOR_BUTTON_SELECTED,
		UICOLOR_NAVIGATOR_BORDER_NORMAL,
		UICOLOR_NAVIGATOR_BORDER_SELECTED,
		UICOLOR_NAVIGATOR_TEXT_NORMAL,
		UICOLOR_NAVIGATOR_TEXT_SELECTED,
		UICOLOR_NAVIGATOR_TEXT_PUSHED,
		UICOLOR_BUTTON_BACKGROUND_NORMAL,
		UICOLOR_BUTTON_BACKGROUND_DISABLED,
		UICOLOR_BUTTON_BACKGROUND_PUSHED,
		UICOLOR_BUTTON_TEXT_NORMAL,
		UICOLOR_BUTTON_TEXT_PUSHED,
		UICOLOR_BUTTON_TEXT_DISABLED,
		UICOLOR_BUTTON_BORDER_LIGHT,
		UICOLOR_BUTTON_BORDER_DARK,
		UICOLOR_BUTTON_BORDER_DISABLED,
		UICOLOR_BUTTON_BORDER_FOCUS,
		UICOLOR_CONTROL_BACKGROUND_NORMAL,
		UICOLOR_CONTROL_BACKGROUND_SELECTED,
		UICOLOR_CONTROL_BACKGROUND_DISABLED,
		UICOLOR_CONTROL_BACKGROUND_READONLY,
		UICOLOR_CONTROL_BACKGROUND_HOVER,
		UICOLOR_CONTROL_BACKGROUND_SORTED,
		UICOLOR_CONTROL_BACKGROUND_EXPANDED,
		UICOLOR_CONTROL_BORDER_NORMAL,
		UICOLOR_CONTROL_BORDER_SELECTED,
		UICOLOR_CONTROL_BORDER_DISABLED,
		UICOLOR_CONTROL_TEXT_NORMAL,
		UICOLOR_CONTROL_TEXT_SELECTED,
		UICOLOR_CONTROL_TEXT_DISABLED,
		UICOLOR_CONTROL_TEXT_READONLY,
		UICOLOR_TOOL_BACKGROUND_NORMAL,
		UICOLOR_TOOL_BACKGROUND_DISABLED,
		UICOLOR_TOOL_BACKGROUND_HOVER,
		UICOLOR_TOOL_BACKGROUND_PUSHED,
		UICOLOR_TOOL_BORDER_NORMAL,
		UICOLOR_TOOL_BORDER_DISABLED,
		UICOLOR_TOOL_BORDER_HOVER,
		UICOLOR_TOOL_BORDER_PUSHED,
		UICOLOR_EDIT_BACKGROUND_NORMAL,
		UICOLOR_EDIT_BACKGROUND_HOVER,
		UICOLOR_EDIT_BACKGROUND_DISABLED,
		UICOLOR_EDIT_BACKGROUND_READONLY,
		UICOLOR_EDIT_TEXT_NORMAL,
		UICOLOR_EDIT_TEXT_DISABLED,
		UICOLOR_EDIT_TEXT_READONLY,
		UICOLOR_TITLE_BACKGROUND,
		UICOLOR_TITLE_TEXT,
		UICOLOR_TITLE_BORDER_LIGHT,
		UICOLOR_TITLE_BORDER_DARK,
		UICOLOR_HEADER_BACKGROUND,
		UICOLOR_HEADER_BORDER,
		UICOLOR_HEADER_SEPARATOR,
		UICOLOR_HEADER_TEXT,
		UICOLOR_TASK_BACKGROUND,
		UICOLOR_TASK_CAPTION,
		UICOLOR_TASK_BORDER,
		UICOLOR_TASK_TEXT,
		UICOLOR_LINK_TEXT_HOVER,
		UICOLOR_LINK_TEXT_NORMAL,
		UICOLOR_STANDARD_BLACK,
		UICOLOR_STANDARD_YELLOW,
		UICOLOR_STANDARD_RED,
		UICOLOR_STANDARD_GREY,
		UICOLOR_STANDARD_LIGHTGREY,
		UICOLOR_STANDARD_WHITE,
		UICOLOR__LAST,
		UICOLOR__INVALID,
	} UITYPE_COLOR;

	class UIPaintManager : public Singleton<UIPaintManager>
	{
	public:
		UIPaintManager();
		virtual ~UIPaintManager();

		void Init();
	};

}

#endif