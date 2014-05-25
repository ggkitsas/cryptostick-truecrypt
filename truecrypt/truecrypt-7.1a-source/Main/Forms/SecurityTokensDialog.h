/*
Developer: ggkitsas
Year: 2014
*/

#ifndef TC_HEADER_Main_Forms_SecurityTokensDialog
#define TC_HEADER_Main_Forms_SecurityTokensDialog

#include "Forms.h"
#include "Common/SecurityToken.h"
#include "Main/Main.h"

namespace TrueCrypt
{
	class SecurityTokensDialog : public SecurityTokensDialogBase
	{
	public:
		SecurityTokensDialog (wxWindow* parent, bool selectionMode = true);
		SecurityTokenInfo* GetSelectedSecurityToken() const {return SelectedSecurityTokenInfo;}

	protected:
		enum
		{
			ColumnSecurityTokenSlotId = 0,
			ColumnSecurityTokenLabel,
			ColumnSecurityTokenKeyfileLabel,
		};

		void FillSecurityTokensList ();
		void OnListItemActivated (wxListEvent& event) { OnOKButtonClick(); }
		void OnListItemDeselected (wxListEvent& event);
		void OnListItemSelected (wxListEvent& event);
		void OnOKButtonClick ();
		void OnOKButtonClick (wxCommandEvent& event) { OnOKButtonClick(); }

		vector <SecurityTokenInfo> SecurityTokenInfoList;
		SecurityTokenInfo* SelectedSecurityTokenInfo;
	};
}

#endif // TC_HEADER_Main_Forms_SecurityTokensDialog
