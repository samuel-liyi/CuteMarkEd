/*
 * Copyright 2013 Christian Loose <christian.loose@hamburg.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "dictionarytest.h"

#include <matcher/isequal.h>
#include <matcherassert.h>
using HamcrestQt::equalTo;

#include <spellchecker/dictionary.h>

void DictionaryTest::returnsLanguageNameForLanguageCode()
{
    Dictionary german("de_DE", "");
    ASSERT_THAT(german.languageName(), equalTo(QStringLiteral("Deutsch")));

    Dictionary americanEnglish("en_US", "");
    ASSERT_THAT(americanEnglish.languageName(), equalTo(QStringLiteral("U.S. English")));
}

void DictionaryTest::returnsCountryNameForLanguage()
{
    Dictionary german("de_DE", "");
    ASSERT_THAT(german.countryName(), equalTo(QStringLiteral("Deutschland")));

    Dictionary americanEnglish("en_US", "");
    ASSERT_THAT(americanEnglish.countryName(), equalTo(QStringLiteral("United States")));
}
