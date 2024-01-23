// TDD for the adding part

#include <gtest/gtest.h>
#include "AddURL.h"
#include "BytesArray.h"
#include "HashFunction.h"
#include "URLlist.h"

using namespace std;

TEST(AddURL, addingURLcheck) {
AddURL* addUrl = new AddURL();
HashFunction* h = new HashFunction(32, 2,1);
BytesArray* bytesArray = new BytesArray(32);
URLlist* urlList = new URLlist();

string key = "www.gmail.com";
vector<int> v = h->getHashes(key);
addUrl->execute(*bytesArray, urlList, key, *h);
EXPECT_TRUE(bytesArray->checkIfIn(v[0]) && bytesArray->checkIfIn(v[1]));
EXPECT_TRUE(urlList->contains(key));

key = "www.facebook.com";
v = h->getHashes(key);
addUrl->execute(*bytesArray, urlList, key, *h);
EXPECT_TRUE(bytesArray->checkIfIn(v[0]) && bytesArray->checkIfIn(v[1]));
EXPECT_TRUE(urlList->contains(key));

key = "www.instagram.com";
v = h->getHashes(key);
addUrl->execute(*bytesArray, urlList, key, *h);
EXPECT_TRUE(bytesArray->checkIfIn(v[0]) && bytesArray->checkIfIn(v[1]));
EXPECT_TRUE(urlList->contains(key));

key = "www.whatsapp.com";
v = h->getHashes(key);
addUrl->execute(*bytesArray, urlList, key, *h);
EXPECT_TRUE(bytesArray->checkIfIn(v[0]) && bytesArray->checkIfIn(v[1]));
EXPECT_TRUE(urlList->contains(key));

EXPECT_FALSE(urlList->contains("www.a.com"));
EXPECT_FALSE(urlList->contains("www.b.com"));
EXPECT_FALSE(urlList->contains("www.c.com"));
EXPECT_FALSE(urlList->contains("www.d.com"));
EXPECT_FALSE(urlList->contains("www.e.com"));

delete urlList;
delete h;
delete bytesArray;
delete addUrl;
}

