#include "folder_file_manager.h"

FolderFileManager::FolderFileManager()
{
    this->_base_dir = "../../root/user/";
    this->_delete_folder_dir = "../../root/delete_all_folder.txt";
    this->_delete_file_dir = "../../root/delete_all_file.txt";

    this->_folder_map = unordered_map<string, vector<string>>();
    this->_file_set = unordered_set<string>();

    this->_init();
    this->_read_delete_file_folder();
}

void FolderFileManager::_init()
{
    mkdir("../../root/");
    ifstream ins;
    ins.open(this->_delete_file_dir);
    if(ins.fail())
    {
        ofstream outs;
        outs.open(this->_delete_file_dir);
        if(outs.fail()) return;
        outs.close();
    }
    ins.close();

    ins.open(this->_delete_folder_dir);
    if(ins.fail())
    {
        ofstream outs;
        outs.open(this->_delete_folder_dir);
        if(outs.fail()) return;
        outs.close();  
    }
    ins.close();

    mkdir(this->_base_dir.c_str());
}

FolderFileManager::~FolderFileManager(){}


bool FolderFileManager::file_exist(const string& path)
{
    if(this->_file_set.count(this->_base_dir + path) > 0) return true;
    return false;
}

bool FolderFileManager::folder_exist(const string& path)
{
    if(this->_folder_map.count(this->_base_dir + path + "/") > 0) return true;
    return false;
}



bool FolderFileManager::add_folder(const string& path)
{
    ofstream outs;
    string file_path = this->_base_dir + path + "/";
    if(this->_folder_map.count(file_path) > 0) return false;
    if(mkdir(file_path.c_str()) == -1) return false;
    this->_folder_map[file_path] = vector<string>();

    // add folder path including ending /
    this->_add_delete_file_folder(file_path, false);
    return true;
}



bool FolderFileManager::add_file(const string& path)
{
    ofstream outs;
    string file_path = this->_base_dir + path;
    if(this->_file_set.count(file_path) > 0) return false;
    outs.open(file_path);
    if(outs.fail()) return false;
    this->_file_set.insert(file_path);
    outs.close();
    
    // only add if no error
    this->_add_delete_file_folder(file_path, true);
    return true;
}

void FolderFileManager::_read_delete_file_folder()
{
    string line;
    ifstream ins;
    ins.open(this->_delete_file_dir);
    if(ins.fail()) return;
    while(getline(ins, line)) this->_file_set.insert(line);
    ins.close();
    ins.open(this->_delete_folder_dir);
    if(ins.fail()) return;
    while(getline(ins, line)) this->_folder_map[line] = vector<string>();
    ins.close();
}


void FolderFileManager::_add_delete_file_folder(const string& file_path, bool control)
{
    ofstream outs;
    if(control) outs.open(this->_delete_file_dir, std::ios_base::app);
    if(!control) outs.open(this->_delete_folder_dir, std::ios_base::app);
    if(outs.fail()) return;
    outs << file_path << endl;
    outs.close();
}



bool FolderFileManager::delete_folder(const string& path)
{
    string file_path = this->_base_dir + path + "/";
    if(!this->_folder_map.count(file_path)) return false;
    if(rmdir(file_path.c_str()) == -1) return false;
    this->_folder_map.erase(file_path);
    ofstream outs;
    outs.open(this->_delete_folder_dir);
    if(outs.fail()) return false;
    for(auto path : this->_folder_map) outs << path.first << endl;
    outs.close();
    return true;
}


bool FolderFileManager::delete_file(const string& path)
{
    string file_path = this->_base_dir + path;
    if(!this->_file_set.count(file_path)) return false;
    if(remove(file_path.c_str()) == -1) return false;
    this->_file_set.erase(file_path);

    ofstream outs;
    outs.open(this->_delete_file_dir);
    if(outs.fail()) return false;
    for(auto path : this->_file_set) outs << path << endl;

    outs.close();
    return true;
}