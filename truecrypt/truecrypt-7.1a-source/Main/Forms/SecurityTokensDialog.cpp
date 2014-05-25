/*
Developer: ggkitsas
Year: 2014
*/

#include "Main/GraphicUserInterface.h"
#include "Common/SecurityToken.h"
#include "SecurityTokensDialog.h"

namespace TrueCrypt
{
	SecurityTokensDialog::SecurityTokensDialog (wxWindow* parent, bool selectionMode)
		: SecurityTokensDialogBase (parent)
	{
		if (selectionMode)
			SetTitle (LangString["SELECT_TOKEN"]);

		// Set up list's layout

		list <int> colPermilles;
	
		SecurityTokensListCtrl->InsertColumn (ColumnSecurityTokenSlotId, LangString["TOKEN_SLOT_ID"], wxLIST_FORMAT_CENTER, 1);
		colPermilles.push_back (102);
		SecurityTokensListCtrl->InsertColumn (ColumnSecurityTokenLabel, LangString["TOKEN_NAME"], wxLIST_FORMAT_LEFT, 1);
		colPermilles.push_back (368);

		FillSecurityTokensList();

		Gui->SetListCtrlWidth (SecurityTokensListCtrl, 65);
		Gui->SetListCtrlHeight (SecurityTokensListCtrl, 16);
		Gui->SetListCtrlColumnWidths (SecurityTokensListCtrl, colPermilles);

		Fit();
		Layout();
		Center();

		OKButton->Disable();
		OKButton->SetDefault();
	}
	
	void SecurityTokensDialog::FillSecurityTokensList()
	{
		wxBusyCursor busy;

		SecurityTokensListCtrl->DeleteAllItems();
		SecurityTokenInfoList = SecurityToken::GetAvailableTokensVector();

		size_t i = 0;
		foreach (const SecurityTokenInfo &info, SecurityTokenInfoList)
		{
			vector <wstring> fields (SecurityTokensListCtrl->GetColumnCount());
			
			fields[ColumnSecurityTokenSlotId] = StringConverter::ToWide ((uint64) info.SlotId);
			fields[ColumnSecurityTokenLabel] = info.Label;

			Gui->AppendToListCtrl (SecurityTokensListCtrl, fields, 0, &SecurityTokenInfoList[i++]); 
		}

		// Dummy item to test dialog functionallity
		/*
			vector <wstring> fields (SecurityTokensListCtrl->GetColumnCount());
			
			fields[ColumnSecurityTokenSlotId] = StringConverter::ToWide ((uint64) 10);
			wchar_t test[] = L"test";
			fields[ColumnSecurityTokenLabel] = test;
			SecurityTokenInfo test_info;
			test_info.Label=L"test";
			Gui->AppendToListCtrl (SecurityTokensListCtrl, fields, 0, &test_info); 
		*/
	}

	void SecurityTokensDialog::OnListItemDeselected (wxListEvent& event)
	{
		if (SecurityTokensListCtrl->GetSelectedItemCount() == 0)
		{
			OKButton->Disable();
		}
	}

	void SecurityTokensDialog::OnListItemSelected (wxListEvent& event)
	{
		printf("OnItemSelected\n");
		if (event.GetItem().GetData() != (wxUIntPtr) nullptr)
		{
			OKButton->Enable();
		}
	}

	void SecurityTokensDialog::OnOKButtonClick ()
	{	
		long item = Gui->GetListCtrlSelectedItem (SecurityTokensListCtrl);
		SelectedSecurityTokenInfo = reinterpret_cast <SecurityTokenInfo*> (SecurityTokensListCtrl->GetItemData (item));
	
		EndModal (wxID_OK);
	}
}
