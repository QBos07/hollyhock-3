class File {
public:
    File();
    ~File();

    int open(const char *path, int flags);
    int getAddr(int offset, const void **addr);
    int read(void *buf, int count);

private:
    bool m_opened;
    int m_fd;
};

class Find {
public:
	Find();
	~Find();

	int findFirst(const wchar_t *path, wchar_t *name, struct File_FindInfo *findInfoBuf);
	int findNext(wchar_t *name, struct File_FindInfo *findInfoBuf);

private:
	bool m_opened;
	int m_findHandle;
};