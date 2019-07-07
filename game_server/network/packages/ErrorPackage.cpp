//
// Created by kir on 07.07.19.
//

#include "ErrorPackage.h"

Package::ResultStatus ErrorPackage::getResultStatus() const
{
    return ResultStatus::Error;
}
