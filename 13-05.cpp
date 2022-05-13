#include <iostream>

using namespace std;

/*

файловая система 
если при записи в файл он будет удален кем-то другим - ошибка записи 
для того, Чтобы этого не было - его надо открывать в эксклюзивном режиме
если идет только чтения без изменения данных - нет смысла в эксклюзивности 

файлы контролирует операционная система 
у файлов есть права доступа 
появляется понятие пользователя. проверяются права пользователя и уровни доступа к файлам
у пользователя есть имя и идентификаторы. их можно дернуть 

winapi, posix
<filesystem> - с 17го стандатра 
<boost/filesystem>

класс path - основной элемент фаловой системы - для унификации путей и тп
path - есть автоматическое преобразование из const char в string

<filesystem>
    std::filesystem::path
        /= - добавляет новый элемент вложенности к текущему пути (глубже по каталогу)
        += - склейка элементов path ен заходя в подкаталог
        remove_filename - удаляет имя файла из пути к этому файлу
        replace_extension - для имени файла заменить расширение 
        iterator - по всему пути можно пройти с помощью итератора. есть и begin и end
    
    std::filesystem::directory_entry
        exist - проверить, связана ли текущаядиректория с файлом
        is_directory - проверить, является ли каталогом
        file_size - узнать размер файла/каталога
        last_write_time - время последнего изменения - вернет в формате std::filesystem::file_time_type - псевдонимом на chrono

    std::filesystem::file_status - класс, который вернется при запросе статуса 
        permissions - права доступа на файл

    std::filesystem::perms - enum class - хранит в человекочитаемом виде элементы, которые позволяют проверить права

    copy - копирует файл или каталог 
    copy_file - копирует только файл
    create_directory - создает 1 каталог 
    create_directories - создает несколько каталогов
    current_path - возвращает текущий путь к каталогу
    exists - проверяет, существует ли файл
    equivalent - сравнивает пути (ведут ли они к одному объекту)
    file_size - получить размер 
    last_write_time - время последнего изменения
    permissions 
    remove - удаляет как файл, так и каталог 
    remove_all - удалить и файл и каталог и его содержимое 
    rename - переназывает файл 
    resize_file - изменяет размер 
    space - позволяет узнать, сколько в файловой системе есть свободного места
    status - статус файла 
    temp_directory_path - все под tmp 



*/

int main() {


    return 0;
}