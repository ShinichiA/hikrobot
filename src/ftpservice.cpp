#include "ftpservice.h"

FtpService::FtpService() {};

FtpService::FtpService(const char *host, const char *user, const char *password) {
    this->host = host;
    this->user = user;
    this->password = password;
}


int FtpService::Connect() {
    int status;
    status = ftp->Connect(host);
    if (status == 0) {
        return status;
    }
    status = ftp->Login(user, password);
    return status;
}

int FtpService::Put(string src, string dst) {
    int status;
    status = ftp->Put(src.c_str(), dst.c_str(), ftplib::image);
    return status;
}

int FtpService::Dir(const char *remote_dir) {
    int status;
    status = ftp->Dir(NULL, remote_dir);
    return status;
}


int FtpService::Quit() {
    int status;
    status = ftp->Quit();
    return status;
}
