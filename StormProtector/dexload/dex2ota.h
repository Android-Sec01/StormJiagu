#pragma once
#include <ctime>

//for dex2oat
namespace art
{
	// ԭ�� http://blog.chinaunix.net/uid-13344516-id-79188.html
	/*
	 *
	 * ����LD_PRELOAD ����art�е�InitLogging ����
	 * �˷��� ����xxxx�ӹ�
	 * ����
	 * DEX_PATH="/data/app/com.catchingnow.icebox-1/oat/arm/base.odex" 
	 * MY_INFO="16880" 
	 * MY_INFO1="4684244" 
	 * MY_INFO2="23" 
	 * LD_PRELOAD="/data/app/com.catchingnow.icebox-1/lib/arm/libshella-0.0.1.so" 
	 * /system/bin/art 
	 * --instruction-set=arm --boot-image=/system/framework/boot.art 
	 * --dex-file=/data/app/com.catchingnow.icebox-1/oat/arm/base.odex 
	 * --oat-file=/data/data/com.catchingnow.icebox/tx_shell/libshellc.so 
	 * --compiler-filter=interpret-only
	 */
	void InitLogging(char* argv[]);
	bool stophook = false;
	void (*oldInitLogging)(char* argv[]);

	//art hook dex2ota open read fstat mmap mprotect write ����
}

