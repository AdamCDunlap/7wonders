#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "optionparser.h"
using namespace std;

struct Arg: public option::Arg
{
    static void printError(const char* msg1, const option::Option& opt, const char* msg2)
    {
        fprintf(stderr, "%s", msg1);
        fwrite(opt.name, opt.namelen, 1, stderr);
        fprintf(stderr, "%s", msg2);
    }
    static option::ArgStatus NumericOrNone(const option::Option& option, bool msg)
    {
        if (option.arg && option.name[option.namelen] != 0) {
            char* endptr = nullptr;
            if (option.arg != 0 && strtol(option.arg, &endptr, 10)){};
            if (endptr != option.arg && *endptr == 0)
              return option::ARG_OK;
            
            
            if (msg) printError("Option '", option, "' requires a numeric argument\n");
            return option::ARG_ILLEGAL;
        } else {
            cout << "Ignore" << endl;
            return option::ARG_IGNORE;
        }
    }
};

enum optionIndex { UNKNOWN, HELP, GIVE_RAND_SEED, SPECIFY_WONDERS };
const option::Descriptor usage[] =
{
 {UNKNOWN,         0,"" , "",       Arg::None,          "USAGE: 7wonders [options] [name]... \n\n"
                                                                "Options:" },
 {HELP,            0,"" , "help",   Arg::None,          "  --help  \tPrint usage and exit." },
 {GIVE_RAND_SEED,  0,"s", "seed",   Arg::NumericOrNone, "  --seed, -s  \tIncrement count." },
 {SPECIFY_WONDERS, 0,"w", "wonders",Arg::None,          "  --wonders, -w  \tSpecify wonder after each name." },
 {0,0,0,0,0,0}
};

int main(int argc, char* argv[]) {

    argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
    option::Stats  stats(usage, argc, argv);
    option::Option* options = new option::Option[stats.options_max];
    option::Option* buffer  = new option::Option[stats.buffer_max];
    option::Parser parse(usage, argc, argv, options, buffer);

    if (parse.error())
        return 1;

    if (options[HELP]) {
        option::printUsage(std::cout, usage);
        return 0;
    }
    
    for (option::Option* opt = options[UNKNOWN]; opt; opt = opt->next())
        cout << "Unknown option: " << opt->name << endl;
    
    for (int i = 0; i < parse.nonOptionsCount(); ++i)
        cout << "Non-option #" << i << ": " << parse.nonOption(i) << endl;

    long srand_val = time(0);
    if (options[GIVE_RAND_SEED]) {
        if(options[GIVE_RAND_SEED].arg) {
            srand_val = strtol(options[GIVE_RAND_SEED].arg, nullptr,10);
        } else {
            srand_val = 0;
        }
    }
    srand(srand_val);
    cout << "Seed: " << srand_val << endl;

    vector<string> names(argv, argv + argc);
    if (names.empty()) {
        names.push_back("Adam");
        names.push_back("Kira");
        names.push_back("Annaliese");
    }
    Game gm{names};
    gm.play();

    delete[] options;
    delete[] buffer;
}
