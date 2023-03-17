#include <iostream>
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include "RepoFile.h"
int main() {
    RepoInFile repo;
    Service service;
    service.setRepo("hotel");
    UI ui(repo, service);
    ui.run_menu();
    return 0;
}
