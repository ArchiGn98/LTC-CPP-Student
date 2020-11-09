#include "pch.h"
#include "Composite.h"
#include "PersistanceManager.h"

TEST(HW3, CompositeJSONFull)
{
    const std::string savePath(PersistanceManager::getCurrPath() +
        "\\HomeWork\\CompositePattern\\");

    sptr_Composite root         = NEW_COMPOSITE();
    sptr_Composite contents     = NEW_COMPOSITE("contents");
    sptr_Composite contents2    = NEW_COMPOSITE("contents2");
    sptr_Composite product1     = NEW_COMPOSITE();
    sptr_Composite product2     = NEW_COMPOSITE();
    sptr_Composite product3     = NEW_COMPOSITE();

    product1->add(NEW_LEAF("orderID", "12345"));
    product1->add(NEW_LEAF("productName", "Product 1"));
    product1->add(NEW_LEAF("quantity", "1"));

    product2->add(NEW_LEAF("productID", "223"));
    product2->add(NEW_LEAF("productName", "Product 2"));
    product2->add(NEW_LEAF("quantity", "1"));

    product3->add(NEW_LEAF("productID", "456498"));
    product3->add(NEW_LEAF("productName", "Product 3"));
    product3->add(NEW_LEAF("quantity", "2"));

    contents->add(product1);
    contents2->add(product2);
    contents2->add(product3);

    root->add(NEW_LEAF("orderID", "21"));
    root->add(NEW_LEAF("shopperName", "Artur Hnoinskyi"));
    root->add(NEW_LEAF("shopperEmail", "ahnoinskyi@luxoft.com"));
    root->add(contents);
    root->add(contents2);

    PersistanceManager pm;

    std::string expected = pm.read(savePath + "CompositeJSONFull.txt");

    // I dont know why in expected appears extra "\n" char
    // Also it works only with consloe mode. 
    // If run test using Test Explorer it fails.
    ASSERT_EQ(root->str() + "\n", expected);
}

TEST(HW3, CompositeJSONGetProductsRoots)
{
    const std::string savePath(PersistanceManager::getCurrPath() +
        "\\HomeWork\\CompositePattern\\");

    sptr_Composite root         = NEW_COMPOSITE();
    sptr_Composite contents     = NEW_COMPOSITE("contents");
    sptr_Composite contents2    = NEW_COMPOSITE("contents2");
    sptr_Composite product1     = NEW_COMPOSITE();
    sptr_Composite product2     = NEW_COMPOSITE();
    sptr_Composite product3     = NEW_COMPOSITE();

    product1->add(NEW_LEAF("orderID", "12345"));
    product1->add(NEW_LEAF("productName", "Product 1"));
    product1->add(NEW_LEAF("quantity", "1"));

    product2->add(NEW_LEAF("productID", "223"));
    product2->add(NEW_LEAF("productName", "Product 2"));
    product2->add(NEW_LEAF("quantity", "1"));

    product3->add(NEW_LEAF("productID", "456498"));
    product3->add(NEW_LEAF("productName", "Product 3"));
    product3->add(NEW_LEAF("quantity", "2"));

    contents->add(product1);
    contents2->add(product2);
    contents2->add(product3);

    root->add(NEW_LEAF("orderID", "21"));
    root->add(NEW_LEAF("shopperName", "Artur Hnoinskyi"));
    root->add(NEW_LEAF("shopperEmail", "ahnoinskyi@luxoft.com"));
    root->add(contents);
    root->add(contents2);

    PersistanceManager pm;

    std::string expected1 =
        pm.read(savePath + "CompositeJSONGetProductsRoots1.txt");
    std::string expected2 =
        pm.read(savePath + "CompositeJSONGetProductsRoots2.txt");
    std::string expected3 =
        pm.read(savePath + "CompositeJSONGetProductsRoots3.txt");

    // I dont know why in expected appears extra "\n" char
    // Also it works only with consloe mode. 
    // If run test using Test Explorer it fails.
    ASSERT_EQ(product1->parentPtr.lock()->str() + "\n", expected1);
    ASSERT_EQ(product2->parentPtr.lock()->str() + "\n", expected2);
    ASSERT_EQ(product3->parentPtr.lock()->str() + "\n", expected3);
}

TEST(HW3, CompositeJSONRemove)
{
    const std::string savePath(PersistanceManager::getCurrPath() +
        "\\HomeWork\\CompositePattern\\");

    sptr_Composite root         = NEW_COMPOSITE();
    sptr_Composite contents     = NEW_COMPOSITE("contents");
    sptr_Composite contents2    = NEW_COMPOSITE("contents2");
    sptr_Composite product1     = NEW_COMPOSITE();
    sptr_Composite product2     = NEW_COMPOSITE();
    sptr_Composite product3     = NEW_COMPOSITE();

    product1->add(NEW_LEAF("orderID", "12345"));
    product1->add(NEW_LEAF("productName", "Product 1"));
    product1->add(NEW_LEAF("quantity", "1"));

    product2->add(NEW_LEAF("productID", "223"));
    product2->add(NEW_LEAF("productName", "Product 2"));
    product2->add(NEW_LEAF("quantity", "1"));

    product3->add(NEW_LEAF("productID", "456498"));
    product3->add(NEW_LEAF("productName", "Product 3"));
    product3->add(NEW_LEAF("quantity", "2"));

    contents->add(product1);
    contents2->add(product2);
    contents2->add(product3);

    root->add(NEW_LEAF("orderID", "21"));
    root->add(NEW_LEAF("shopperName", "Artur Hnoinskyi"));
    root->add(NEW_LEAF("shopperEmail", "ahnoinskyi@luxoft.com"));
    root->add(contents);
    root->add(contents2);

    root->remove(contents);
    contents2->remove(product2);

    PersistanceManager pm;

    std::string expected = pm.read(savePath + "CompositeJSONRemove.txt");

    // I dont know why in expected appears extra "\n" char
    // Also it works only with consloe mode. 
    // If run test using Test Explorer it fails.
    ASSERT_EQ(root->str() + "\n", expected);
}

TEST(HW3, CompositeJSONChilds)
{
    const std::string savePath(PersistanceManager::getCurrPath() +
        "\\HomeWork\\CompositePattern\\");

    sptr_Composite root         = NEW_COMPOSITE();
    sptr_Composite contents     = NEW_COMPOSITE("contents");
    sptr_Composite contents2    = NEW_COMPOSITE("contents2");
    sptr_Composite product1     = NEW_COMPOSITE();
    sptr_Composite product2     = NEW_COMPOSITE();
    sptr_Composite product3     = NEW_COMPOSITE();

    product1->add(NEW_LEAF("orderID", "12345"));
    product1->add(NEW_LEAF("productName", "Product 1"));
    product1->add(NEW_LEAF("quantity", "1"));

    product2->add(NEW_LEAF("productID", "223"));
    product2->add(NEW_LEAF("productName", "Product 2"));
    product2->add(NEW_LEAF("quantity", "1"));

    product3->add(NEW_LEAF("productID", "456498"));
    product3->add(NEW_LEAF("productName", "Product 3"));
    product3->add(NEW_LEAF("quantity", "2"));

    contents->add(product1);
    contents2->add(product2);
    contents2->add(product3);

    root->add(NEW_LEAF("orderID", "21"));
    root->add(NEW_LEAF("shopperName", "Artur Hnoinskyi"));
    root->add(NEW_LEAF("shopperEmail", "ahnoinskyi@luxoft.com"));
    root->add(contents);
    root->add(contents2);

    auto childContents = contents->getChild();
    auto childContents2 = contents2->getChild();

    PersistanceManager pm;

    std::string expected1 = pm.read(savePath + "CompositeJSONChilds1.txt");
    std::string expected2 = pm.read(savePath + "CompositeJSONChilds2.txt");

    // I dont know why in expected appears extra "\n" char
    // Also it works only with consloe mode. 
    // If run test using Test Explorer it fails.
    ASSERT_EQ(childContents->str() + "\n", expected1);
    ASSERT_EQ(childContents2->str() + "\n", expected2);
}