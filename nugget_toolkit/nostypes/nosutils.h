#ifndef NOSUTILS_H
#define NOSUTILS_H

#include <google/protobuf/text_format.h>
#include <stdio.h>

using namespace google::protobuf;

namespace nostypes {

/* Printer related */
static TextFormat::Printer
    g_NosPrinter;  // printer used by different print functions

// Generic printer related for protobuf functions
void printNosCommand(std::string app, std::string cmd, Message &request,
                     Message &response);
void initNosPrinter();

std::string messageToString(Message &m);

/* Find NosApp and NosCmd */
void printAppList();

}  // namespace nostypes

#endif  // NOSUTILS_H
