
#include "support.h"

using namespace std;
int main(int argc, char **argv)
{
    support *sup = new support();
    string res = sup->run_command(argc, argv);
    cout << res << "\n";
    delete sup;
    return 0;
}