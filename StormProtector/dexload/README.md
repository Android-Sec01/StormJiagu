### ǰ��
����˼·�ο���MultiDex������ο���ĳĳ�ӹ̡�
### ����
![](http://images2015.cnblogs.com/blog/836057/201703/836057-20170316093418432-1173085699.png)
### Davlikvm
Davlik �ڴ���ؼ����Ƚϳ��죬��������Ҳ�Ƚ϶�
���÷ǳ����ķ�����
ʵ���������ϵͳ�������������Ͳ���������
```cpp
Dalvik_dalvik_system_DexFile_openDexFile_bytearray(const u4* args,JValue* pResult)
```
�������������Ҫע����������⣺
ע�����
* �õ�gDvm.userDexFiles���ָ��
���������

```cpp
void dvmInternalNativeShutdown()
{
    dvmHashTableFree(gDvm.userDexFiles);
}
```
Hook dvmHashTableFree����Ȼ�����dvmInternalNativeShutdown������ͨ��dvmHashTableFree�����õ�ָ�루�������Կ�ѩ��̳��

ͨ�����ַ�������ʵ�ּ򵥵��ڴ���غͶ�dex����
### Art
art �ڴ���ؼ����������ϲ���,Ҳûʵ�������ġ�˼·�ο�ĳĳ�ӹ̵Ĵ��롣���������Կ��ܺ�һ�㡣
������ͨ���������DexFiel.loadDex

```java
static public DexFile loadDex(String sourcePathName, String outputPathName,
        int flags) throws IOException
```
�ڵ���loadDex֮ǰhook������Щ����

```cpp
Hook::hookMethod(arthandle, "open", (void*)artmyopen, (void**)(&artoldopen));
    Hook::hookMethod(arthandle, "read", (void*)artmyread, (void**)(&artoldread));
    Hook::hookMethod(arthandle, "munmap", (void*)artmymunmap, (void**)(&artoldmunmap));
    Hook::hookMethod(arthandle, "mmap", (void*)artmymmap, (void**)(&artoldmmap));
    Hook::hookMethod(arthandle, "fstat", (void*)artmyfstat, (void**)(&artoldfstat));
    Hook::hookMethod(arthandle, "fork", (void*)artmyfork, (void**)(&artoldfork));
    Hook::hookMethod(arthandle, "execv", (void*)artmyexecv, (void**)(&artoldexecv));
```
���ļ���ȡ��������һЩС�������Ϳ���ʵ��dex�ļ��򵥵ļ��ܡ�����Ҳ����ʵ��dex"����ؼ���"���������ַ�����̫���������������˵�����ȶ�һ�㡣������Ҳ��Ժ�һ�㡣

### ʹ�÷�����

### С�᣺
���������Ƚϼ򵥡��������̻��ǱȽϸ��ӵģ������漰��art dex2oat��������Ҳ������ġ�������4.4 ��6.0��7.1 ϵͳ����������û����
��Ϥ��dex���ص��������̡��ǳ���лĳĳ�ӹ�
�����Ժ������ῪԴ��