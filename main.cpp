#include <unistd.h> // for user permission check
#include <iostream>
#include <sys/mount.h>  // for mount op
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>// for FS ops
#undef BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem/fstream.hpp>

namespace fs = boost::filesystem;
int fsmapping(fs::path &path);
int main(int argc, char *argv[]) {
    //this program should run as root,
    //procedure to check permissions
    auto uid = getuid();
    //setuid(0);
    auto euid = geteuid();
    if (uid == euid && euid != 0) {
        std::cout << "no proper permission detected, please re-run as root!\n";
        return 1;
    }
    if (argc == 1) {
        //not enough arguments
        std::cout << "no path provided, cant mount.";
        return 1;
    }
    const char *sourcePath = argv[1];// path to device provided by arguments
    const char *targetPath = "/media/zap/";  // mount to path
    std::cout << "path provided:" << sourcePath << "\n";
    std::cout << "trying to mount to :" << targetPath << "\n";
    int returnValue = mount(sourcePath, targetPath, "", MS_SHARED, "");
    if (returnValue == 0) {
        //mounted successfully and filesystem mapping will start
        fs::path path=fs::path(targetPath);
        int b=fsmapping(path);
    } else {
        //mounted failed
        perror("");
        std::cout << "mount failed\n";
    }
    //unmount
    if(!umount(targetPath)){
        //unmounted device
        std::cout<<"unmounted device\n";
    }else{
        //unmounted not completed
        std::cout<<"couldn't unmount device\n";
    }

}


int fsmapping(fs::path &path){
    if (!exists(path))
        return 0;
    //fs::directory_iterator end_itr;//last iterator


    //for (fs::directory_iterator iter(path);iter!=end_itr;++iter){
     //   std::cout<<iter->path()<<"\n";
    //}
}