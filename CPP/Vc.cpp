int system_hide(CString strFile,CString strParam)
{
	SHELLEXECUTEINFO shellExeInfo;
	memset(&shellExeInfo, 0, sizeof(shellExeInfo));
	shellExeInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	shellExeInfo.fMask = SEE_MASK_DOENVSUBST | SEE_MASK_FLAG_DDEWAIT | 0x04000000 | SEE_MASK_NOCLOSEPROCESS | SEE_MASK_NO_CONSOLE; 
	shellExeInfo.lpVerb = "open";
	shellExeInfo.hwnd = NULL;
	shellExeInfo.lpFile = strFile;//"regsvr32.exe";//这个替换成你的复制命令 
	shellExeInfo.lpParameters = strParam;//strVideoShortPath.c_str();//这是你命令的参数 
	shellExeInfo.lpDirectory = NULL;
	shellExeInfo.nShow = SW_HIDE;
	shellExeInfo.hInstApp = NULL;

	::ShellExecuteEx(&shellExeInfo);
	if(shellExeInfo.hProcess)
	{ 
		::WaitForSingleObject(shellExeInfo.hProcess, INFINITE); 
	}
	DWORD ret;
	GetExitCodeProcess(shellExeInfo.hProcess, &ret);
	return ret;
}
