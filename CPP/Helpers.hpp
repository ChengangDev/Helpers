#include <vector>
#include <sstream>
using namespace std;
class Helpers
{
    public:
        static vector<string> split(string s, char delim)
        {
            stringstream temp (stringstream::in | stringstream::out);
            vector<string> elems(0);
            if (s.size() == 0 || delim == 0)
                return elems;
            for each(char c in s)
            {
                if(c == delim)
                {
                    elems.push_back(temp.str());
                    temp = stringstream(stringstream::in | stringstream::out);
                }
                else
                    temp << c;
            }
            if (temp.str().size() > 0)
                elems.push_back(temp.str());
                return elems;
            }

        //Splits string s with a list of delimiters in delims (it's just a list, like if we wanted to
        //split at the following letters, a, b, c we would make delims="abc".
        static vector<string> split(string s, string delims)
        {
            stringstream temp (stringstream::in | stringstream::out);
            vector<string> elems(0);
            bool found;
            if(s.size() == 0 || delims.size() == 0)
                return elems;
            for each(char c in s)
            {
                found = false;
                for each(char d in delims)
                {
                    if (c == d)
                    {
                        elems.push_back(temp.str());
                        temp = stringstream(stringstream::in | stringstream::out);
                        found = true;
                        break;
                    }
                }
                if(!found)
                    temp << c;
            }
            if(temp.str().size() > 0)
                elems.push_back(temp.str());
            return elems;
        }
};
