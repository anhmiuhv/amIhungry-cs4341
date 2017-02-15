#include "dictionary.h"


std::map<std::string, double> dictHumidity;
std::map<std::string, double> dictTemp;
std::map<std::string, double> dictDay;
std::map<std::string, double> dictIcyTrue;
std::map<std::string, double> dictSnowTrue;
std::map<std::string, double> dictCloudTrue;
std::map<std::string, double> dictExamTrue;
std::map<std::string, double> dictStressTrue;
void initDicts() {
    dictHumidity.emplace("low", 0.2);
    dictHumidity.emplace("medium", 0.5);
    dictHumidity.emplace("high", 0.3);
    dictTemp.emplace("warm", 0.1);
    dictTemp.emplace("mild", 0.4);
    dictTemp.emplace("cold", 0.5);
    dictDay.emplace("weekend", 0.2);
    dictDay.emplace("weekday", 0.8);
    dictIcyTrue.emplace("lowwarm", 0.001);
    dictIcyTrue.emplace("lowmild", 0.01);
    dictIcyTrue.emplace("lowcold", 0.05);
    dictIcyTrue.emplace("mediumwarm", 0.001);
    dictIcyTrue.emplace("mediummild", 0.03);
    dictIcyTrue.emplace("mediumcold", 0.2);
    dictIcyTrue.emplace("highwarm", 0.005);
    dictIcyTrue.emplace("highmild", 0.01);
    dictIcyTrue.emplace("highcold", 0.35);
    dictSnowTrue.emplace("lowwarm", 0.00001);
    dictSnowTrue.emplace("lowmild", 0.001);
    dictSnowTrue.emplace("lowcold", 0.1);
    dictSnowTrue.emplace("mediumwarm", 0.00001);
    dictSnowTrue.emplace("mediummild", 0.0001);
    dictSnowTrue.emplace("mediumcold", 0.25);
    dictSnowTrue.emplace("highwarm", 0.0001);
    dictSnowTrue.emplace("highmild", 0.001);
    dictSnowTrue.emplace("highcold", 0.4);
    dictCloudTrue.emplace("false", 0.3);
    dictCloudTrue.emplace("true", 0.9);
    dictExamTrue.emplace("falseweekend", 0.001);
    dictExamTrue.emplace("falseweekday", 0.1);
    dictExamTrue.emplace("trueweekend", 0.0001);
    dictExamTrue.emplace("trueweekday", 0.3);
    dictStressTrue.emplace("falsefalse", 0.001);
    dictStressTrue.emplace("falsetrue", 0.1);
    dictStressTrue.emplace("truefalse", 0.0001);
    dictStressTrue.emplace("truetrue", 0.3);
}
