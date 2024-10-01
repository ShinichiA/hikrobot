#include "include.h"
#include "ftplib.h"


using namespace std;


class FtpService {
public:
    FtpService();

    FtpService(const char *host, const char *user, const char *password);

    const char *host;
    const char *user;
    const char *password;

    ftplib *ftp = new ftplib();

    int Connect();

    int Put(string src, string dst);

    int Dir(const char *remote_dir);

    int Quit();
};
