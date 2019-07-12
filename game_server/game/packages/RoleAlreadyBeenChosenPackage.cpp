//
// Created by kir on 12.07.19.
//

#include "RoleAlreadyBeenChosenPackage.h"

using namespace std::string_literals;

RoleAlreadyBeenChosenPackage::RoleAlreadyBeenChosenPackage(const CardMetadata *roleMetadata) :
        ErrorPackage(7),
        _roleMetadata(roleMetadata)
{

}

std::string_view RoleAlreadyBeenChosenPackage::getErrorMessage() const
{
    auto title = _roleMetadata->getCardTitle();
    return "Роль "s + std::string(title.data(), title.size()) + " уже была выбрана!";
}
