#include "variable_storage.hpp"

#include <utility>

#include "file/file.hpp"
#include "file/parser.hpp"

//--------------------------------------------------------------------------------

core::VariableStorage::VariableStorage()
{
    reloadSettings();
}

core::VariableStorage&
core::VariableStorage::getInstance()
{
    static VariableStorage instance;
    return instance;
}

void
core::VariableStorage::reloadSettings() noexcept
{
    auto& parser  = file::Parser::getInstance();
    auto settings = file::File::getLines("main_settings.conf");
    for (auto& str : settings)
    {
        auto var = parser.asVariable(str);
        switch (var.type)
        {
            case file::Parser::Variable::Type::Int:
                mInts[var.name] = valueSetter(var.value);
                break;
            case file::Parser::Variable::Type::Bool:
                mFlags[var.name] = turnOnOff(var.value);
                break;
            case file::Parser::Variable::Type::String:
                mWords[var.name] = var.value;
                break;
        }
    }
}

//--------------------------------------------------------------------------------

bool
core::VariableStorage::checkFlag(const std::string& aName,
                                 bool aDefault) const noexcept
{
    bool result = aDefault;
    auto it     = mFlags.find(aName);
    if (it != mFlags.end())
    {
        result = it->second;
    }
    return result;
}

int
core::VariableStorage::getInt(const std::string& aName,
                              int aDefault) const noexcept
{
    int result = aDefault;
    auto it    = mInts.find(aName);
    if (it != mInts.end())
    {
        result = it->second;
    }
    return result;
}

std::string
core::VariableStorage::getWord(const std::string& aName,
                               std::string aDefault) const noexcept
{
    std::string result = aDefault;
    auto it            = mWords.find(aName);
    if (it != mWords.end())
    {
        result = it->second;
    }
    return result;
}

//--------------------------------------------------------------------------------

bool
core::VariableStorage::turnOnOff(const std::string& s) noexcept
{
    bool result = false;
    if (s == "on") result = true;
    return result;
}

int
core::VariableStorage::valueSetter(const std::string& s) noexcept
{
    return std::stoi(s);
}
