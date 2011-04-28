/*!
 * \file   Translation.h
 * \date   27 April 2011
 * \author StefanP.MUC
 * \brief  handles the translation
 */

#ifndef TRANSLATION_H_
#define TRANSLATION_H_

#include <vector>
#include <string>

#include "tinygettext.hpp"

#define _(String) (Translation::getSingletonPtr()->translate(String))

class Translation : public Ogre::Singleton<Translation>
{
    public:
        Translation();
        static Translation& getSingleton();
        static Translation* getSingletonPtr();

        inline const std::vector<std::string>* getLanguageList() const{return &languageList;}
        inline std::string translate(const std::string& original) {return dictionary.translate(original);}

    private:
        ~Translation();
        Translation(const Translation&);

        std::vector<std::string> languageList;
        tinygettext::DictionaryManager dictMgr;
        tinygettext::Dictionary dictionary;
};

#endif /* TRANSLATION_H_ */