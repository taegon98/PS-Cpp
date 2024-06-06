#include <string>
#include <vector>
using namespace std;

string step_1(string id) {
    for (int i = 0; i < id.size(); i++) {
        if (id[i] >= 65 and id[i] <= 90) {
            id[i] += 32;
        }
    }
    return id;
}

string step_2(string id) {
    string temp = "";
    
    for (int i = 0; i < id.size(); i++) {
        if ((id[i] >= 97 and id[i] <= 122) or
            (id[i] >= 48 and id[i] <= 57) or
            (id[i] == '-' or id[i] == '_' or id[i] == '.')) {
            temp += id[i];
        }
    }
    return temp;
}

string step_3(string id) {
     string temp = "";
    
    for (int i = 0; i < id.size(); i++) {
        bool flag = false;
        while (id[i] == '.') {
            flag = true;
            i++;
            
            if (i >= id.size()) {
                temp += '.';
                return temp;
            }
        }
        if (flag) temp += '.';
        temp += id[i];
    }
    return temp;
}

string step_4(string id) {
    if (id[0] == '.') {
        id = id.substr(1);
    }
    
    if (id[id.size() - 1] == '.') {
        id = id.substr(0, id.size() - 1);
    }
    return id;
}

string step_5(string id) {
    if (!id.size()) id = "a";
    return id;
}

string step_6(string id) {
    if (id.size() >= 16) {
        id = id.substr(0, 15);
        
        if (id[id.size() - 1] == '.') {
            id = id.substr(0, id.size() - 1);
        }
    }
    return id;
}

string step_7(string id) {
    if (id.size() <= 2) {
        char ch = id[id.size() - 1];
        
        while(id.size() < 3) {
            id += ch;
        }
    }
    return id;
}

string solution(string new_id) {
    string answer = "";
    
    new_id = step_1(new_id);
    new_id = step_2(new_id);
    new_id = step_3(new_id);
    new_id = step_4(new_id);
    new_id = step_5(new_id);
    new_id = step_6(new_id);
    answer = step_7(new_id);
    
    return answer;
}