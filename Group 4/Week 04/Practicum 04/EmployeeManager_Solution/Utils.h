//
// Created by Boris Bozhilov on 3/17/2026.
//

#ifndef EMPLOYEEMANAGER_UTILS_H
#define EMPLOYEEMANAGER_UTILS_H

namespace Utils{

    enum class ErrorCode {
        OK,
        NotFound,
        Duplicate,
        InvalidInput,
        ArrayIsFull
    };

}

#endif //EMPLOYEEMANAGER_UTILS_H