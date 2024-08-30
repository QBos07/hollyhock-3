#include "files.hpp"
#include <sdk/os/file.hpp>

File::File() : m_opened(false), m_fd(-1) {}
File::~File() {
	if (m_opened) {
		File_Close(m_fd);
	}
}

int File::open(const char *path, int flags) {
	m_fd = File_Open(path, flags);
	m_opened = true;
	return m_fd;
}

int File::getAddr(int offset, const void **addr) {
	return ::File_GetAddr(m_fd, offset, addr);
}

int File::read(void *buf, int count) {
	return ::File_Read(m_fd, buf, count);
}

Find::Find() : m_opened(false), m_findHandle(-1)  {}
Find::~Find() {
	if (m_opened) {
		File_FindClose(m_findHandle);
	}
}

int Find::findFirst(const wchar_t *path, wchar_t *name, struct File_FindInfo *findInfoBuf) {
	int ret = File_FindFirst(path, &m_findHandle, name, findInfoBuf);
	m_opened = true;
	return ret;
}

int Find::findNext(wchar_t *name, struct File_FindInfo *findInfoBuf) {
	return File_FindNext(m_findHandle, name, findInfoBuf);
}