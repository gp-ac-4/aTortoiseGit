// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2008-2011 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#pragma once

#include "HorizontalResizableStandAloneDialog.h"
#include "HistoryCombo.h"
#include "HyperLink.h"
#include "registry.h"
// CPullFetchDlg dialog

class CPullFetchDlg : public CHorizontalResizableStandAloneDialog
{
	DECLARE_DYNAMIC(CPullFetchDlg)

public:
	CPullFetchDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPullFetchDlg();

// Dialog Data
	enum { IDD = IDD_PULLFETCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CHistoryCombo	m_Remote;
	CHistoryCombo	m_Other;
	CHistoryCombo	m_RemoteBranch;
	virtual BOOL OnInitDialog();
	CRegString	m_RemoteReg;
	CRegDWORD	m_regRebase;
	CRegDWORD	m_regAutoLoadPutty;

	DECLARE_MESSAGE_MAP()
public:
	BOOL		m_IsPull;
	bool		m_bAllowRebase;
	BOOL		m_bAutoLoad;
	BOOL		m_bRebase;
	BOOL		m_bPrune;
	BOOL		m_bSquash;
	BOOL		m_bNoFF;
	BOOL		m_bNoCommit;
	BOOL		m_bAutoLoadEnable;
	CString		m_PreSelectRemote;

	CString		m_RemoteURL;
	CString		m_RemoteBranchName;

protected:
	CString		m_configPullRemote;
	CString		m_configPullBranch;

	CHyperLink	m_RemoteManage;

	afx_msg void OnBnClickedRd();
	afx_msg void OnBnClickedOk();
	void Refresh();
	afx_msg void OnStnClickedRemoteManage();
	afx_msg void OnBnClickedButtonBrowseRef();
};
