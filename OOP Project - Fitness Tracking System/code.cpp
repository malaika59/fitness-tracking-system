#include <iostream>
#include <fstream>
#include <cstring>
#include <dirent.h>

using namespace std;

const int max_user = 100; // Maximum number of users

class User
{
private:
    static int UserID;
    int UserCount;
    string username;
    string password;
    string name;
    float height;
    float weight;
    float bmi;

public:
    // Constructor for login/signup
    User() : username(""), password(""), name(""), height(0), weight(0) {}

    User(string username, string password, string name, float height, float weight)
        : username(username), password(password), name(name), height(height), weight(weight) {}

    // Getter for username
    string getUsername()
    {
        return username;
    }
    float getWeight()
    {
        return weight;
    }
    float getHeight()
    {
        return height;
    }
    float calculateBMI()
    {
        if (height > 0 && weight > 0)
        {
            return weight / (height * height);
        }
        else
        {
            cerr << "Invalid height or weight values for BMI calculation.\n";
            return 0.0; // or any other suitable default value
        }
    }
    void updateUserDataFromFile(string filename)
    {
        ifstream userFile(filename);
        if (userFile.is_open())
        {
            // Skip password line
            string line;
            getline(userFile, line);

            // Read other user data
            getline(userFile, name);
            userFile >> height;
            userFile >> weight;

            userFile.close();
        }
        else
        {
            cerr << "Unable to open file for reading.\n";
        }
    }

    // Member function to sign up a new user
    static bool signup(User users[], int userCount, string username, string password, string name, float height, float weight)
    {
        // Check if the username already exists
        for (int i = 0; i < userCount; ++i)
        {
            if (users[i].getUsername() == username)
            {
                return false; // User already exists
            }
        }

        // Add the new user
        if (userCount < max_user)
        {
            users[userCount++] = User(username, password, name, height, weight);
            // Save the user data to an individual file
            ofstream userfile(username);
            if (userfile.is_open())
            {
                userfile << password << "\n";
                userfile << name << "\n";
                userfile << height << "\n";
                userfile << weight << "\n";
                userfile.close(); // Signup successful
                return true;
            }
            else
            {
                cerr << "Unable to open file for writing.\n";
                return false;
            }
        }
        else
        {
            return false; // Maximum number of users reached
        }
    }

    // Member function to authenticate a user during login
    static bool login(User users[], int userCount, string username, string password)
    {
        string storedPassword;
        ifstream userFile(username);
        if (!userFile.is_open())
        {
            cerr << "Error opening file!" << endl;
            return false;
        }
        else
        {
            if (getline(userFile, storedPassword))
            {
                if (storedPassword == password)
                {
                    userFile.close();
                    return true; // Login successful
                }
            }
        }
        userFile.close();
        return false; // Invalid username or password
    }
};

const int bananas_cal = 150;
const int apple_cal = 52;
const int mango_cal = 70;
const int cucumber_cal = 78;
const int carrot_cal = 270;
const int legume_cal = 115;
const int nuggets_cal = 45;
const int roll_cal = 145;
const int cake_cal = 476;
const int cookies_cal = 260;
const int bread_cal = 67;
const int other_fruit = 90;
const int other_fried = 200;
const int other_baked = 422;
const int other_vege = 25;

class food
{
protected:
    int baked_cal;
    int fried_cal;
    int fruit_cal;
    int veg_cal;
    int nutseed_cal;
    int fluid_cal;
    int vegl_cal;
    int fruitl_cal;
    int bananas_count;
    int apples_count;
    int mangoes_count;
    int otherfruit_count;
    int cucumber_count;
    int carrot_count;
    int legume_count;
    int othervege_count;
    int nuggets_count;
    int roll_count;
    int otherfried_count;
    int cake_count;
    int cookies_count;
    int bread_count;
    int otherbaked_count;
    // loose calorie
    int greentea_cups;
    int herbaltea_cups;
    int black_coffee_cups;
    int otherfluids;
    int almond_count;
    int cashew_count;
    int chia_seeds;
    int other_nuts;
    int Tomatoes;
    int Zucchini;
    int Spinach;
    int other_veget;
    int Peaches;
    int Grapefruit;
    int Strawberries;
    int other_fruits;
};

class gainfood : public food
{
public:
    int get_bananacount()
    {
        cout << "Enter no. of bananas: ";
        cin >> bananas_count;
        return bananas_count;
    }

    int get_applecount()
    {
        cout << "Enter no. of apples: ";
        cin >> apples_count;
        return apples_count;
    }

    int get_mangocount()
    {
        cout << "Enter no. of mangoes: ";
        cin >> mangoes_count;
        return mangoes_count;
    }

    int get_othercount()
    {
        cout << "Enter no. of other fruits: ";
        cin >> otherfruit_count;
        return otherfruit_count;
    }
    int get_cucumbercount()
    {
        cout << "Enter no. of cucumber rolls: ";
        cin >> cucumber_count;
        return cucumber_count;
    }
    int get_carrotcount()
    {
        cout << "Enter no. of carrots: ";
        cin >> carrot_count;
        return carrot_count;
    }
    int get_legumecount()
    {
        cout << "Enter no. of legumes: ";
        cin >> legume_count;
        return legume_count;
    }
    int get_othervegcount()
    {
        cout << "Enter no. of other vegetables: ";
        cin >> othervege_count;
        return othervege_count;
    }
    int get_nuggetcount()
    {
        cout << "Enter no. of nugget: ";
        cin >> nuggets_count;
        return nuggets_count;
    }
    int get_rollcount()
    {
        cout << "Enter no. of roll: ";
        cin >> roll_count;
        return roll_count;
    }
    int get_otherfriedcount()
    {
        cout << "Enter no. of other fried items you took: ";
        cin >> otherfried_count;
        return otherfried_count;
    }
    int get_cakecount()
    {
        cout << "Enter no. of cake slices you ate: ";
        cin >> cake_count;
        return cake_count;
    }
    int get_cookiescount()
    {
        cout << "Enter no. of cookies: ";
        cin >> cookies_count;
        return cookies_count;
    }
    int get_breadcount()
    {
        cout << "Enter no. of bread slices: ";
        cin >> bread_count;
        return bread_count;
    }
    int get_otherbakedcount()
    {
        cout << "Enter no. of other baked items you took: ";
        cin >> otherbaked_count;
        return otherbaked_count;
    }
    int getUser_cal()
    {
        return (fried_cal + fruit_cal + veg_cal + baked_cal);
    }

    // getters for getting count of each item consumed. These will be used for saving in file
    int bananacount()
    {
        return bananas_count;
    }
    int applecount()
    {
        return apples_count;
    }
    int mangocount()
    {
        return mangoes_count;
    }
    int otherFruitcount()
    {
        return otherfruit_count;
    }
    int cucumbercount()
    {
        return cucumber_count;
    }
    int carrotcount()
    {
        return carrot_count;
    }
    int legumecount()
    {
        return legume_count;
    }
    int other_vegtcount()
    {
        return othervege_count;
    }
    int nuggetcount()
    {
        return nuggets_count;
    }
    int rollcount()
    {
        return roll_count;
    }
    int other_friedcount()
    {
        return otherfried_count;
    }
    int cakecount()
    {
        return cake_count;
    }
    int cookiescount()
    {
        return cookies_count;
    }
    int breadcount()
    {
        return bread_count;
    }
    int other_bakedcount()
    {
        return otherbaked_count;
    }

    void food_intake()
    {
        while (true)
        {
            string food_type;
            cout << "----------------------" << endl;
            cout << "Select food type:\n"
                 << "1. Baked items\n"
                 << "2. Fried items\n"
                 << "3. Vegetables\n"
                 << "4. Fruits\n"
                 << "5. Go on the next step\n"
                 << "----------------------" << endl
                 << "Your choice: ";
            cin >> food_type;

            if (food_type == "4")
            {
                string fruit_type;
                cout << "----------------------" << endl;
                cout << "Enter the type of fruit\n"
                     << "1. Banana \n"
                     << "2. Apple\n"
                     << "3. Mangoes\n"
                     << "4. Others\n"
                     << "5. For going on main food menu\n"
                     << "----------------------" << endl
                     << "Your choice: ";

                cin >> fruit_type;

                if (fruit_type == "1")
                {
                    while (1)
                    {
                        int count = get_bananacount();
                        if (count <= 10)
                        {
                            fruit_cal += count * bananas_cal;
                            cout << "Calories gained after eating these bananas are: " << fruit_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "2")
                {
                    while (1)
                    {
                        int count = get_applecount();
                        if (count <= 10)
                        {
                            fruit_cal += count * apple_cal;
                            cout << "Calories gained after eating these apples are: " << fruit_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "3")
                {
                    while (1)
                    {
                        int count = get_mangocount();
                        if (count <= 10)
                        {
                            fruit_cal += count * mango_cal;
                            cout << "Calories gained after eating these mangoes are: " << fruit_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "4")
                {
                    while (1)
                    {
                        int count = get_othercount();
                        if (count <= 10)
                        {
                            fruit_cal += count * other_fruit;
                            cout << "Calories gained after eating other fruits are: " << fruit_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "5")
                {
                    continue;
                }
            }
            if (food_type == "2")
            {
                string fry_type;
                cout << "----------------------" << endl;
                cout << "Enter the type of fried item:\n"
                     << "1. Nugget \n"
                     << "2. Roll\n"
                     << "3. Others\n"
                     << "4. For going on main food menu\n"
                     << "----------------------" << endl
                     << "Your choice: ";

                cin >> fry_type;

                if (fry_type == "1")
                {
                    while (1)
                    {
                        int count = get_nuggetcount();
                        if (count <= 10)
                        {
                            fried_cal += count * nuggets_cal;
                            cout << "Calories gained after eating these nuggets are: " << fried_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fry_type == "2")
                {
                    while (1)
                    {
                        int count = get_rollcount();
                        if (count <= 10)
                        {
                            fried_cal += count * roll_cal;
                            cout << "Calories gained after eating these rolls are: " << fried_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fry_type == "3")
                {
                    while (1)
                    {
                        int count = get_otherfriedcount();
                        if (count <= 10)
                        {
                            fried_cal += count * other_fried;
                            cout << "Calories gained after eating other fried items are: " << fried_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }

                else if (fry_type == "4")
                {
                    continue;
                }
            }

            if (food_type == "1")
            {
                string bake_type;
                cout << "----------------------" << endl;
                cout << "Enter the type of baked item\n"
                     << "1. Cake \n"
                     << "2. Cookie\n"
                     << "3. Bread\n"
                     << "4. Others\n"
                     << "5. For going on main food menu\n"
                     << "----------------------" << endl
                     << "Your choice: ";

                cin >> bake_type;

                if (bake_type == "1")
                {
                    while (1)
                    {
                        int count = get_cakecount();
                        if (count <= 10)
                        {
                            baked_cal += count * cake_cal;
                            cout << "Calories gained after eating these cakes are: " << baked_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (bake_type == "2")
                {
                    while (1)
                    {
                        int count = get_cookiescount();
                        if (count <= 10)
                        {
                            baked_cal += count * cookies_cal;
                            cout << "Calories gained after eating these cookies are: " << baked_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (bake_type == "3")
                {
                    while (1)
                    {
                        int count = get_breadcount();
                        if (count <= 10)
                        {
                            baked_cal += count * bread_cal;
                            cout << "Calories gained after eating these breads are: " << baked_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (bake_type == "4")
                {
                    while (1)
                    {
                        int count = get_othercount();
                        if (count <= 10)
                        {
                            baked_cal += count * other_baked;
                            cout << "Calories gained after eating other baked items are: " << baked_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (bake_type == "5")
                {
                    continue;
                }
            }

            if (food_type == "3")
            {
                string vege_type;
                cout << "----------------------" << endl;
                cout << "Enter the type of vegetable:\n"
                     << "1. Carrot \n"
                     << "2. Legumes\n"
                     << "3. Cucumber\n"
                     << "4. Others\n"
                     << "5. For going on main food menu\n"
                     << "----------------------" << endl;
                cout << "Your choice: ";
                cin >> vege_type;

                if (vege_type == "1")
                {
                    while (1)
                    {
                        int count = get_carrotcount();
                        if (count <= 10)
                        {
                            veg_cal += count * carrot_cal;
                            cout << "Calories gained after eating these carrots are: " << veg_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "2")
                {
                    while (1)
                    {
                        int count = get_legumecount();
                        if (count <= 10)
                        {
                            veg_cal += count * legume_cal;
                            cout << "Calories gained after eating these legumes are: " << veg_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "3")
                {
                    while (1)
                    {
                        int count = get_cucumbercount();
                        if (count <= 10)
                        {
                            veg_cal += count * cucumber_cal;
                            cout << "Calories gained after eating these cucumbers are: " << veg_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "4")
                {
                    while (1)
                    {
                        int count = get_othervegcount();
                        if (count <= 10)
                        {
                            veg_cal += count * other_vege;
                            cout << "Calories gained after eating other vegetables are: " << veg_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "5")
                {
                    continue;
                }
            }

            else if (food_type == "5")
            {
                cout << "Your total calories consumed by food are: " << getUser_cal() << endl;
                cout << "Going to the next step...\n";
                break; // Exit the loop
            }
        }
    }
};
// loose
const int peach_cal = 39;
const int strawberry_cal = 32;
const int grapefruit_cal = 42;
const int other_cal = 15;
const int blackcoffee_cal = 2;
const int greentea_cal = 2;
const int herbaltea_cal = 1;
const int almond_cal = 60;
const int cashew_cal = 55;
const int chia_cal = 38;
const int othernut_cal = 20;
const int tomato_cal = 18;
const int spinach_cal = 23;
const int zucchini_cal = 17;
const int othervegt_cal = 10;

class loosefood : public food
{
public:
    int get_almondcount()
    {
        cout << "Enter no. of almonds: ";
        cin >> almond_count;
        return almond_count;
    }

    int get_cashewcount()
    {
        cout << "Enter no. of cashews: ";
        cin >> cashew_count;
        return cashew_count;
    }

    int get_chiacount()
    {
        cout << "Enter no. of chia seeds (estimation): ";
        cin >> chia_seeds;
        return chia_seeds;
    }

    int get_othernutcount()
    {
        cout << "Enter no. of other nuts: ";
        cin >> other_nuts;
        return other_nuts;
    }
    int get_peachescount()
    {
        cout << "Enter no. of peaches: ";
        cin >> Peaches;
        return Peaches;
    }
    int get_grapefruitcount()
    {
        cout << "Enter no. of grapefruits: ";
        cin >> Grapefruit;
        return Grapefruit;
    }
    int get_strawberrycount()
    {
        cout << "Enter no. of strawberries: ";
        cin >> Strawberries;
        return Strawberries;
    }
    int get_otherfruitcount()
    {
        cout << "Enter no. of other fruits: ";
        cin >> other_fruits;
        return other_fruits;
    }

    int get_tomatocount()
    {
        cout << "Enter no. of tomatoes: ";
        cin >> Tomatoes;
        return Tomatoes;
    }
    int get_zucchinicount()
    {
        cout << "Enter no. of zucchinis: ";
        cin >> Zucchini;
        return Zucchini;
    }

    int get_spinachcount()
    {
        cout << "Enter no. of spinach leaflets: ";
        cin >> Spinach;
        return Spinach;
    }
    int get_othervegtcount()
    {
        cout << "Enter no. of other vegetables: ";
        cin >> other_veget;
        return other_veget;
    }
    int get_greenteacount()
    {
        cout << "Enter no. of green tea cups you took: ";
        cin >> greentea_cups;
        return greentea_cups;
    }
    int get_herbalteacount()
    {
        cout << "Enter no. of herbal tea cups you took: ";
        cin >> herbaltea_cups;
        return herbaltea_cups;
    }
    int get_blackcoffeecount()
    {
        cout << "Enter no. of black coffee cups you took: ";
        cin >> black_coffee_cups;
        return black_coffee_cups;
    }
    int getUserCal()
    {
        return (nutseed_cal + fluid_cal + vegl_cal + fruitl_cal);
    }

    // getters
    int almondcount()
    {
        return almond_count;
    }
    int cashewcount()
    {
        return cashew_count;
    }
    int chiacount()
    {
        return chia_seeds;
    }
    int othernutcount()
    {
        return other_nuts;
    }
    int peachescount()
    {
        return Peaches;
    }
    int grapefruitcount()
    {
        return Grapefruit;
    }
    int strawberrycount()
    {
        return Strawberries;
    }
    int otherfruitcount()
    {
        return other_fruits;
    }
    int tomatocount()
    {
        return Tomatoes;
    }
    int zucchinicount()
    {
        return Zucchini;
    }
    int spinachcount()
    {
        return Spinach;
    }
    int othervegtcount()
    {
        return other_veget;
    }
    int greenteacount()
    {
        return greentea_cups;
    }
    int herbalteacount()
    {
        return herbaltea_cups;
    }
    int blackcoffeecount()
    {
        return black_coffee_cups;
    }

    void food_intake()
    {
        while (true)
        {
            string food_type;
            cout << "Select food type:\n"
                 << "1. Nuts & seeds\n"
                 << "2. Fluids\n"
                 << "3. Vegetables\n"
                 << "4. Fruits\n"
                 << "5. Go on the next step\n"
                 << "Your choice: ";
            cin >> food_type;

            if (food_type == "4")
            {
                string fruit_type;
                cout << "Enter the type of fruit\n"
                     << "1. Peaches \n"
                     << "2. Strawberries\n"
                     << "3. Grapefruit\n"
                     << "4. Others\n"
                     << "5. For going on main food menu\n"
                     << "Your choice: ";

                cin >> fruit_type;

                if (fruit_type == "1")
                {
                    while (1)
                    {
                        int count = get_peachescount();
                        if (count <= 10)
                        {
                            fruitl_cal += count * peach_cal;
                            cout << "Calories gained after eating these peaches are: " << fruitl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "2")
                {
                    while (1)
                    {
                        int count = get_strawberrycount();
                        if (count <= 10)
                        {
                            fruitl_cal += count * strawberry_cal;
                            cout << "Calories gained after eating these strawberries are: " << fruitl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "3")
                {
                    while (1)
                    {
                        int count = get_grapefruitcount();
                        if (count <= 10)
                        {
                            fruitl_cal += count * grapefruit_cal;
                            cout << "Calories gained after eating these grape fruits are: " << fruitl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "4")
                {
                    while (1)
                    {
                        int count = get_otherfruitcount();
                        if (count <= 10)
                        {
                            fruitl_cal += count * other_cal;
                            cout << "Calories gained after eating other fruits are: " << fruitl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fruit_type == "5")
                {
                    continue;
                }
            }
            if (food_type == "2")
            {
                string fluid_type;
                cout << "Enter the type of fluids:\n"
                     << "1. Black coffee \n"
                     << "2. Green tea\n"
                     << "3. Herbal tea\n"
                     << "4. For going on main food menu\n"
                     << "Your choice: ";

                cin >> fluid_type;

                if (fluid_type == "1")
                {
                    while (1)
                    {
                        int count = get_blackcoffeecount();
                        if (count <= 10)
                        {
                            fluid_cal += count * blackcoffee_cal;
                            cout << "Calories gained after having black coffee are: " << fluid_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fluid_type == "2")
                {
                    while (1)
                    {
                        int count = greenteacount();
                        if (count <= 10)
                        {
                            fluid_cal += count * greentea_cal;
                            cout << "Calories gained after having green tea are: " << fluid_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (fluid_type == "3")
                {
                    while (1)
                    {
                        int count = get_herbalteacount();
                        if (count <= 10)
                        {
                            fluid_cal += count * herbaltea_cal;
                            cout << "Calories gained after having herbal tea are: " << fluid_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }

                else if (fluid_type == "4")
                {
                    continue;
                }
            }

            if (food_type == "1")
            {
                string nuts_type;
                cout << "Enter the type of nuts and seeds item:\n"
                     << "1. Almonds \n"
                     << "2. Cashews\n"
                     << "3. Chia seeds\n"
                     << "4. Others\n"
                     << "5. For going on main food menu\n";

                cin >> nuts_type;

                if (nuts_type == "1")
                {
                    while (1)
                    {
                        int count = get_almondcount();
                        if (count <= 10)
                        {
                            nutseed_cal += count * almond_cal;
                            cout << "Calories gained after eating these almonds are: " << nutseed_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (nuts_type == "2")
                {
                    while (1)
                    {
                        int count = get_cashewcount();
                        if (count <= 10)
                        {
                            nutseed_cal += count * cashew_cal;
                            cout << "Calories gained after eating these cashews are: " << nutseed_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (nuts_type == "3")
                {
                    while (1)
                    {
                        int count = get_chiacount();
                        if (count <= 10)
                        {
                            nutseed_cal += count * chia_cal;
                            cout << "Calories gained after eating these chia seeds are: " << nutseed_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (nuts_type == "4")
                {
                    while (1)
                    {
                        int count = get_othernutcount();
                        if (count <= 10)
                        {
                            nutseed_cal += count * other_nuts;
                            cout << "Calories gained after eating other nuts are: " << nutseed_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (nuts_type == "5")
                {
                    continue;
                }
            }

            if (food_type == "3")
            {
                string vege_type;
                cout << "Enter the type of vegetable\n"
                     << "1. Tomato \n"
                     << "2. Spinach\n"
                     << "3. Zucchini\n"
                     << "4. Others\n"
                     << "5. For going on main food menu\n";

                cin >> vege_type;

                if (vege_type == "1")
                {
                    while (1)
                    {
                        int count = get_tomatocount();
                        if (count <= 10)
                        {
                            vegl_cal += count * tomato_cal;
                            cout << "Calories gained after eating these tomatoes are: " << vegl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "2")
                {
                    while (1)
                    {
                        int count = get_tomatocount();
                        if (count <= 10)
                        {
                            vegl_cal += count * tomato_cal;
                            cout << "Calories gained after eating these tomatoes are: " << vegl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "3")
                {
                    while (1)
                    {
                        int count = get_zucchinicount();
                        if (count <= 10)
                        {
                            vegl_cal += count * zucchini_cal;
                            cout << "Calories gained after eating these zucchini are: " << vegl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "4")
                {
                    while (1)
                    {
                        int count = get_othervegtcount();
                        if (count <= 10)
                        {
                            vegl_cal += count * other_veget;
                            cout << "Calories gained after eating other vegetables are: " << vegl_cal << endl;
                            cout << "----------------------" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter valid intake quantity (within 10):" << endl;
                            continue;
                        }
                    }
                }
                else if (vege_type == "5")
                {
                    continue;
                }
            }

            else if (food_type == "5")
            {
                cout << "Your total calories consumed by food are: " << getUserCal() << endl;
                cout << "Going to the next step...\n";
                break; // Exit the loop
            }
        }
    }
};

//////////EXERCISE///////
////GAIN EXERCISE
const int squats_cal = 5;
const int deadlifts_cal = 5;
const int benchpress_cal = 7;
const int othercompound_cal = 8;
const int bicepdumbell_cal = 2;
const int tricepdumbell_cal = 5;
const int lunges_cal = 5;
const int otherisolation_cal = 5;
const int weighteddips_cal = 6;
const int weightedcrunches_cal = 6;
const int otherweighted_cal = 2;
const int kettlebell_cal = 9;
const int medicineball_cal = 2;
const int otherfunctional_cal = 2;

// lose k const attributes
const int running_cal = 15;
const int walking_cal = 10;
const int swimming_cal = 20;
const int othercardio_cal = 10;
const int basketball_cal = 15;
const int cricket_cal = 15;
const int soccer_cal = 20;
const int othersports_cal = 25;
const int weightlifting_cal = 20;
const int planks_cal = 25;
const int russiantwists_cal = 16;
const int othercore_cal = 10;
const int ropeskipping_cal = 30;
const int ropejumping_cal = 25;
const int danceaerobics_cal = 20;
const int otheraerobics_cal = 15;

class exercise
{
protected:
    int compoundex_cal;
    int isolationex_cal;
    int weightedex_cal;
    int functionalex_cal;
    int cardio_cal;
    int sports_cal;
    int core_cal;
    int aerobics_cal;
    int squats_time;
    int deadlifts_time;
    int benchpress_time;
    int othercompound_time;
    int lunges_time;
    int bicepdumbell_time;
    int tricepdumbell_time;
    int otherisolation_time;
    int weighteddips_time;
    int weightedcrunches_time;
    int otherweighted_time;
    int kettlebellswings_time;
    int medicineball_time;
    int otherfunctional_time;
    int running_time;
    int walking_time;
    int swimming_time;
    int othercardio_time;
    int basketball_time;
    int cricket_time;
    int soccer_time;
    int othersports_time;
    int weightlifting_time;
    int planks_time;
    int russiantwists_time;
    int othercore_time;
    int ropeskipping_time;
    int ropejumping_time;
    int danceaerobics_time;
    int otheraerobics_time;
};

class gainexercise : public exercise
{
public:
    int get_squatstime()
    {
        cout << "Enter the time (in minutes) for which you've done squat exercise: ";
        cin >> squats_time;
        return squats_time;
    }

    int get_benchpresstime()
    {
        cout << "Enter the time (in minutes) for which you've done bench press exercise: ";
        cin >> benchpress_time;
        return benchpress_time;
    }

    int get_deadlifts()
    {
        cout << "Enter the time (in minutes) for which you've done deadlift exercise: ";
        cin >> deadlifts_time;
        return deadlifts_time;
    }

    int get_othercompound()
    {
        cout << "Enter the time (in minutes) for which you've done other compound exercise activities: ";
        cin >> othercompound_time;
        return othercompound_time;
    }

    int get_bicepdumbelltime()
    {
        cout << "Enter the time (in minutes) for which you've done dumbells for biceps: ";
        cin >> bicepdumbell_time;
        return bicepdumbell_time;
    }

    int get_tricepdumbelltime()
    {
        cout << "Enter the time (in minutes) for which you've done dumbells for triceps: ";
        cin >> tricepdumbell_time;
        return tricepdumbell_time;
    }

    int get_lungestime()
    {
        cout << "Enter the time (in minutes) for which you've done lunges exercises: ";
        cin >> lunges_time;
        return lunges_time;
    }

    int get_otherisolationtime()
    {
        cout << "Enter the time (in minutes) for which you've done other isolated exercise activities: ";
        cin >> otherisolation_time;
        return otherisolation_time;
    }

    int get_weighteddips_time()
    {
        cout << "Enter the time (in minutes) for which you've done weighted dips exercise: ";
        cin >> weighteddips_time;
        return weighteddips_time;
    }

    int get_weightedcrunches_time()
    {
        cout << "Enter the time (in minutes) for which you've done weighted crunches exercise: ";
        cin >> weightedcrunches_time;
        return weightedcrunches_time;
    }

    int get_otherweighted_time()
    {
        cout << "Enter the time (in minutes) for which you've done other weighted exercise activities: ";
        cin >> otherweighted_time;
        return otherweighted_time;
    }

    int get_kettlebell_time()
    {
        cout << "Enter the time (in minutes) for which you've done kettlebell swings exercise: ";
        cin >> kettlebellswings_time;
        return kettlebellswings_time;
    }

    int get_medicinebell_time()
    {
        cout << "Enter the time (in minutes) for which you've done medicine ball exercise: ";
        cin >> medicineball_time;
        return medicineball_time;
    }

    int get_otherfunctional_time()
    {
        cout << "Enter the time (in minutes) for which you've done other functional exercise activities: ";
        cin >> otherfunctional_time;
        return otherfunctional_time;
    }

    int getUsercal()
    {
        return (compoundex_cal + isolationex_cal + weightedex_cal + functionalex_cal);
    }

    // getters for getting time of every exercise performed by user
    int squatstime()
    {
        return squats_time;
    }
    int benchpresstime()
    {
        return benchpress_time;
    }
    int deadlifts()
    {
        return deadlifts_time;
    }
    int othercompund()
    {
        return othercompound_time;
    }
    int bicpedumbelltime()
    {
        return bicepdumbell_time;
    }
    int tricepdumbelltime()
    {
        return tricepdumbell_time;
    }
    int lungestime()
    {
        return lunges_time;
    }
    int otherisolationtime()
    {
        return otherisolation_time;
    }
    int weighteddipstime()
    {
        return weighteddips_time;
    }
    int weightedcrunchestime()
    {
        return weightedcrunches_time;
    }
    int otherweightedtime()
    {
        return otherweighted_time;
    }
    int kettlebelltime()
    {
        return kettlebellswings_time;
    }
    int medicinebelltime()
    {
        return medicineball_time;
    }
    int otherfunctionaltime()
    {
        return otherfunctional_time;
    }

    void exercise_intake()
    {
        while (true)
        {
            string ex_type;

            cout << "Select exercise type:\n"
                 << "1. Compound exercise\n"
                 << "2. Isolation exercise\n"
                 << "3. Weighted exercises\n"
                 << "4. Functional exercises\n"
                 << "5. Go to the next step\n"
                 << "Your choice: ";
            cin >> ex_type;

            if (ex_type == "1")
            {
                string compound_type;
                cout << "Enter the type of compound exercises:\n"
                     << "1. Squats exercise\n"
                     << "2. Deadlifts exercise\n"
                     << "3. Benchpress exercise\n"
                     << "4. Others\n"
                     << "5. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> compound_type;

                if (compound_type == "1")
                {
                    while (1)
                    {
                        int count = get_squatstime();
                        if (count <= 30 && count > 0)
                        {
                            compoundex_cal += count * squats_cal;
                            cout << "Calories gained after doing squats are: " << compoundex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (compound_type == "2")
                {
                    while (1)
                    {
                        int count = get_deadlifts();
                        if (count <= 30 && count > 0)
                        {
                            compoundex_cal += count * deadlifts_cal;
                            cout << "Calories gained after doing deadlifts are: " << compoundex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (compound_type == "3")
                {
                    while (1)
                    {
                        int count = get_benchpresstime();
                        if (count <= 30 && count > 0)
                        {
                            compoundex_cal += count * benchpress_cal;
                            cout << "Calories gained after doing brenchpress are: " << compoundex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (compound_type == "4")
                {
                    while (1)
                    {
                        int count = get_othercompound();
                        if (count <= 30 && count > 0)
                        {
                            compoundex_cal += count * othercompound_cal;
                            cout << "Calories gained after doing other compound exercises are: " << compoundex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (compound_type == "5")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (ex_type == "2")
            {
                string iso_type;

                cout << "Enter the type of isolation exercise:\n"
                     << "1. Bicep exercise\n"
                     << "2. Tricep exercise\n"
                     << "3. Lunges exercise\n"
                     << "4. Others\n"
                     << "5. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> iso_type;

                if (iso_type == "1")
                {
                    while (1)
                    {
                        int count = get_bicepdumbelltime();
                        if (count <= 30 && count > 0)
                        {
                            isolationex_cal += count * bicepdumbell_cal;
                            cout << "Calories gained after doing bicep exercises are: " << isolationex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (iso_type == "2")
                {
                    while (1)
                    {
                        int count = get_tricepdumbelltime();
                        if (count <= 30 && count > 0)
                        {
                            isolationex_cal += count * tricepdumbell_cal;
                            cout << "Calories gained after doing tricep exercises are: " << isolationex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (iso_type == "3")
                {
                    while (1)
                    {
                        int count = get_lungestime();
                        if (count <= 30 && count > 0)
                        {
                            isolationex_cal += count * lunges_cal;
                            cout << "Calories gained after doing lunges exercises are: " << isolationex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (iso_type == "4")
                {
                    while (1)
                    {
                        int count = get_otherisolationtime();
                        if (count <= 30 && count > 0)
                        {
                            isolationex_cal += count * otherisolation_cal;
                            cout << "Calories gained after doing other isolation exercises are: " << isolationex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (iso_type == "5")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (ex_type == "3")
            {
                string wei_type;

                cout << "Enter the type of weighted exercise:\n"
                     << "1. Weighted dips exercise\n"
                     << "2. Weighted crunches exercise\n"
                     << "3. Others\n"
                     << "4. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> wei_type;

                if (wei_type == "1")
                {
                    while (1)
                    {
                        int count = get_weighteddips_time();
                        if (count <= 30 && count > 0)
                        {
                            weightedex_cal += count * weighteddips_cal;
                            cout << "Calories gained after doing weighted dips are: " << weightedex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (wei_type == "2")
                {
                    while (1)
                    {
                        int count = get_weightedcrunches_time();
                        if (count <= 30 && count > 0)
                        {
                            weightedex_cal += count * weightedcrunches_cal;
                            cout << "Calories gained after doing weighted crunches are: " << weightedex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (wei_type == "3")
                {
                    while (1)
                    {
                        int count = get_otherweighted_time();
                        if (count <= 30 && count > 0)
                        {
                            weightedex_cal += count * otherweighted_cal;
                            cout << "Calories gained after doing other weighted exercises are: " << weightedex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (wei_type == "4")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (ex_type == "4")
            {
                string fun_type;

                cout << "Enter the type of functional exercise:\n"
                     << "1. Kettle bell swings exercise\n"
                     << "2. Medicine ball exercise\n"
                     << "3. Others\n"
                     << "4. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> fun_type;

                if (fun_type == "1")
                {
                    while (1)
                    {
                        int count = get_kettlebell_time();
                        if (count <= 30 && count > 0)
                        {
                            functionalex_cal += count * kettlebell_cal;
                            cout << "Calories gained after doing kettlebell swings are: " << functionalex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (fun_type == "2")
                {
                    while (1)
                    {
                        int count = get_medicinebell_time();
                        if (count <= 30 && count > 0)
                        {
                            functionalex_cal += count * medicineball_cal;
                            cout << "Calories gained after doing medicine ball are: " << functionalex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (fun_type == "3")
                {
                    while (1)
                    {
                        int count = get_otherfunctional_time();
                        if (count <= 30 && count > 0)
                        {
                            functionalex_cal += count * otherfunctional_cal;
                            cout << "Calories gained after doing other functional exercises are: " << functionalex_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration (within 30)!" << endl;
                            continue;
                        }
                    }
                }
                else if (fun_type == "4")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (ex_type == "5")
            {
                cout << "Total calories gained by performing exercise: " << getUsercal() << endl;
                cout << "Going to the next step...\n";
                break; // Exit the loop
            }
        }
    }
};
class LooseExercise : public exercise
{
public:
    int getRunningTime()
    {
        cout << "Enter the time (in minutes) for running exercise: ";
        cin >> running_time;
        return running_time;
    }

    int getWalkingTime()
    {
        cout << "Enter the time (in minutes) for walking exercise: ";
        cin >> walking_time;
        return walking_time;
    }

    int getSwimmingTime()
    {
        cout << "Enter the time (in minutes) for swimming exercise: ";
        cin >> swimming_time;
        return swimming_time;
    }

    int getOtherCardioTime()
    {
        cout << "Enter the time (in minutes) for other cardio exercises: ";
        cin >> othercardio_time;
        return othercardio_time;
    }

    int getBasketballTime()
    {
        cout << "Enter the time (in minutes) for playing basketball: ";
        cin >> basketball_time;
        return basketball_time;
    }

    int getCricketTime()
    {
        cout << "Enter the time (in minutes) for playing cricket: ";
        cin >> cricket_time;
        return cricket_time;
    }

    int getSoccerTime()
    {
        cout << "Enter the time (in minutes) for playing soccer: ";
        cin >> soccer_time;
        return soccer_time;
    }

    int getOtherSportsTime()
    {
        cout << "Enter the time (in minutes) for other sports: ";
        cin >> othersports_time;
        return othersports_time;
    }

    int getWeightliftingTime()
    {
        cout << "Enter the time (in minutes) for weightlifting: ";
        cin >> weightlifting_time;
        return weightlifting_time;
    }

    int getPlanksTime()
    {
        cout << "Enter the time (in minutes) for doing planks: ";
        cin >> planks_time;
        return planks_time;
    }

    int getRussianTwistsTime()
    {
        cout << "Enter the time (in minutes) for doing Russian twists: ";
        cin >> russiantwists_time;
        return russiantwists_time;
    }

    int getOtherCoreTime()
    {
        cout << "Enter the time (in minutes) for other core exercises: ";
        cin >> othercore_time;
        return othercore_time;
    }

    int getRopeSkippingTime()
    {
        cout << "Enter the time (in minutes) for rope skipping exercise: ";
        cin >> ropeskipping_time;
        return ropeskipping_time;
    }

    int getRopeJumpingTime()
    {
        cout << "Enter the time (in minutes) for rope jumping exercise: ";
        cin >> ropejumping_time;
        return ropejumping_time;
    }

    int getDanceAerobicsTime()
    {
        cout << "Enter the time (in minutes) for dance aerobics: ";
        cin >> danceaerobics_time;
        return danceaerobics_time;
    }

    int getOtherAerobicsTime()
    {
        cout << "Enter the time (in minutes) for other aerobics exercises: ";
        cin >> otheraerobics_time;
        return otheraerobics_time;
    }

    int getusercal()
    {
        return (cardio_cal + sports_cal + core_cal + aerobics_cal);
    }

    // getters for getting time of every exercise performed
    int RunningTime()
    {
        return running_time;
    }
    int WalkingTime()
    {
        return walking_time;
    }
    int SwimmingTime()
    {
        return swimming_time;
    }
    int OtherCardioTime()
    {
        return othercardio_time;
    }
    int BasketballTime()
    {
        return basketball_time;
    }
    int CricketTime()
    {
        return cricket_time;
    }
    int SoccerTime()
    {
        return soccer_time;
    }
    int OtherSportsTime()
    {
        return othersports_time;
    }
    int WeightliftingTime()
    {
        return weightlifting_time;
    }
    int PlanksTime()
    {
        return planks_time;
    }
    int RussianTwistsTime()
    {
        return russiantwists_time;
    }
    int OtherCoreTime()
    {
        return othercore_time;
    }
    int RopeSkippingTime()
    {
        return ropeskipping_time;
    }
    int RopeJumpingTime()
    {
        return ropejumping_time;
    }
    int DanceAerobicsTime()
    {
        return danceaerobics_time;
    }
    int OtherAerobicsTime()
    {
        return otheraerobics_time;
    }

    void exerciseIntake()
    {
        while (true)
        {
            string exType;
            cout << "Following are some exercises which help in weight loss\n"
                 << "Select exercise type:\n"
                 << "1. Cardiovascular exercise\n"
                 << "2. Sports exercise\n"
                 << "3. Core exercises\n"
                 << "4. Aerobics exercises\n"
                 << "5. Go to the next step\n"
                 << "Your choice: ";
            cin >> exType;

            if (exType == "1")
            {
                string cardiovascularType;
                cout << "Enter the type of cardiovascular exercises:\n"
                     << "1. Running exercise\n"
                     << "2. Walking exercise\n"
                     << "3. Swimming exercise\n"
                     << "4. Other cardio exercises\n"
                     << "5. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> cardiovascularType;

                if (cardiovascularType == "1")
                {
                    while (1)
                    {
                        int count = getRunningTime();
                        if (count < 30 && count > 0)
                        {
                            cardio_cal += count * running_cal;
                            cout << "Calories lost after running are: " << cardio_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (cardiovascularType == "2")
                {
                    while (1)
                    {
                        int count = getWalkingTime();
                        if (count < 30 && count > 0)
                        {
                            cardio_cal += count * walking_cal;
                            cout << "Calories lost after walking are: " << cardio_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (cardiovascularType == "3")
                {
                    while (1)
                    {
                        int count = getSwimmingTime();
                        if (count < 30 && count > 0)
                        {
                            cardio_cal += count * swimming_cal;
                            cout << "Calories lost after swimming are: " << cardio_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (cardiovascularType == "4")
                {
                    while (1)
                    {
                        int count = getOtherCardioTime();
                        if (count < 30 && count > 0)
                        {
                            cardio_cal += count * othercardio_cal;
                            cout << "Calories lost after other cardio exercises are: " << cardio_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (cardiovascularType == "5")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (exType == "2")
            {
                string sportsType;
                cout << "Enter the type of sports exercises:\n"
                     << "1. Basketball exercise\n"
                     << "2. Soccer exercise\n"
                     << "3. Cricket exercise\n"
                     << "4. Other sports\n"
                     << "5. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> sportsType;

                if (sportsType == "1")
                {
                    while (1)
                    {
                        int count = getBasketballTime();
                        if (count < 30 && count > 0)
                        {
                            sports_cal += count * basketball_cal;
                            cout << "Calories lost after playing basketball are: " << sports_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (sportsType == "2")
                {
                    while (1)
                    {
                        int count = getSoccerTime();
                        if (count < 30 && count > 0)
                        {
                            sports_cal += count * soccer_cal;
                            cout << "Calories lost after playing soccer are: " << sports_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (sportsType == "3")
                {
                    while (1)
                    {
                        int count = getCricketTime();
                        if (count < 30 && count > 0)
                        {
                            sports_cal += count * cricket_cal;
                            cout << "Calories lost after playing cricket are: " << sports_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (sportsType == "4")
                {
                    while (1)
                    {
                        int count = getOtherSportsTime();
                        if (count < 30 && count > 0)
                        {
                            sports_cal += count * othersports_cal;
                            cout << "Calories lost after playing other sports are: " << sports_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (sportsType == "5")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (exType == "3")
            {
                string coreType;
                cout << "Enter the type of core exercises:\n"
                     << "1. Weightlifting exercise\n"
                     << "2. Planks exercise\n"
                     << "3. Russian twists exercise\n"
                     << "4. Other core exercises\n"
                     << "5. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> coreType;

                if (coreType == "1")
                {
                    while (1)
                    {
                        int count = getWeightliftingTime();
                        if (count < 30 && count > 0)
                        {
                            core_cal += count * weightlifting_cal;
                            cout << "Calories lost after weightlifting are: " << core_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (coreType == "2")
                {
                    while (1)
                    {
                        int count = getPlanksTime();
                        if (count < 30 && count > 0)
                        {
                            core_cal += count * planks_cal;
                            cout << "Calories lost after planks are: " << core_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (coreType == "3")
                {
                    while (1)
                    {
                        int count = getRussianTwistsTime();
                        if (count < 30 && count > 0)
                        {
                            core_cal += count * russiantwists_cal;
                            cout << "Calories lost after russian twists are: " << core_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (coreType == "4")
                {
                    while (1)
                    {
                        int count = getOtherCoreTime();
                        if (count < 30 && count > 0)
                        {
                            core_cal += count * othercore_cal;
                            cout << "Calories lost after other core exercises are: " << core_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (coreType == "5")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (exType == "4")
            {
                string aerobicsType;
                cout << "Enter the type of aerobics exercises:\n"
                     << "1. Rope jumping exercise\n"
                     << "2. Rope skipping exercise\n"
                     << "3. Dance aerobics exercise\n"
                     << "4. Other aerobics exercises\n"
                     << "5. Go to the main exercise menu\n"
                     << "Your choice: ";

                cin >> aerobicsType;

                if (aerobicsType == "1")
                {
                    while (1)
                    {
                        int count = getRopeJumpingTime();
                        if (count < 30 && count > 0)
                        {
                            aerobics_cal += count * ropejumping_cal;
                            cout << "Calories lost after rope jumping are: " << aerobics_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (aerobicsType == "2")
                {
                    while (1)
                    {
                        int count = getRopeSkippingTime();
                        if (count < 30 && count > 0)
                        {
                            aerobics_cal += count * ropeskipping_cal;
                            cout << "Calories lost after rope skipping are: " << aerobics_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (aerobicsType == "3")
                {
                    while (1)
                    {
                        int count = getDanceAerobicsTime();
                        if (count < 30 && count > 0)
                        {
                            aerobics_cal += count * danceaerobics_cal;
                            cout << "Calories lost after dance aerobics are: " << aerobics_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (aerobicsType == "4")
                {
                    while (1)
                    {
                        int count = getOtherAerobicsTime();
                        if (count < 30 && count > 0)
                        {
                            aerobics_cal += count * otheraerobics_cal;
                            cout << "Calories lost after other aerobic exercises are: " << aerobics_cal << endl;
                            break;
                        }
                        else
                        {
                            cout << "Enter a valid time duration! (within 30)" << endl;
                            continue;
                        }
                    }
                }
                else if (aerobicsType == "5")
                {
                    // Go back to the main exercise menu
                    continue;
                }
            }
            else if (exType == "5")
            {
                cout << "Total calories lost by performing exercise: " << getusercal() << endl;
                cout << "Going to the next step...\n";
                break; // Exit the loop
            }
        }
    }
};

class dietPlan
{
public:
    static void gain_diet_plan()
    {
        cout << "\nYou should eat food that can help in gaining weight!\n"
             << "Following are some fruits which help in rapid gaining of weight:\n"
             << "1. Banana \n"
             << "2. Apple\n"
             << "3. Mangoes\n"
             << "Following are some fried items which help in rapid gaining of weight:\n"
             << "1. Nugget \n"
             << "2. Roll\n"
             << "Following are some baked items which help in rapid gaining of weight:\n"
             << "1. Cake \n"
             << "2. Cookie\n"
             << "3. Bread\n"
             << "Following are some vegetables which help in rapid gaining of weight:\n"
             << "1. Carrot \n"
             << "2. Legumes\n"
             << "3. Cucumber\n"
             << "\n\nThere are some exercises alonwith food that can help in gaining weight.\n"
             << "These exercises are compound, isolated, weighted and functional.\n"
             << "Some compound exercises that help in rapid gaining of weight:\n"
             << "1. Squats exercise\n"
             << "2. Deadlifts exercise\n"
             << "3. Benchpress exercise\n"
             << "Some isolation exercises that help in rapid gaining of weight:\n"
             << "1. Bicep exercise\n"
             << "2. Tricep exercise\n"
             << "3. Lunges exercise\n"
             << "Some weighted exercises that help in rapid gaining of weight:\n"
             << "1. Weighted dips exercise\n"
             << "2. Weighted crunches exercise\n"
             << "Some functional exercises that help in rapid gaining of weight:\n"
             << "1. Kettle bell swings exercise\n"
             << "2. Medicine ball exercise\n"
             << "\n\nBy following above given suggestions you can achieve your goal!\n"
             << endl;
    }

    static void loose_dietplan()
    {
        cout << "You should consume low calorie food and should perform some exercises to loose calories that you've gained.\n"
             << "Such kind of food include fruits, vegetables, nuts and seeds and some kinds of fluids.\n"
             << "Following are some fruits which help in rapid loosing of weight:\n"
             << "1. Peaches \n"
             << "2. Strawberries\n"
             << "3. Grapefruit\n"
             << "Following are some fluids which help in rapid loosing of weight:\n"
             << "1. Black coffee \n"
             << "2. Green tea\n"
             << "3. Herbal tea\n"
             << "Following are some nuts & seed items which help in rapid loosing of weight:\n"
             << "1. Almonds \n"
             << "2. Cashews\n"
             << "3. Chia seeds\n"
             << "Following are some vegetables which help in rapid loosing of weight\n"
             << "1. Tomato \n"
             << "2. Spinach\n"
             << "3. Zucchini\n"
             << "\nSome types of exercises that help in loosing weight include cardiovascular, sports, core and aerobics.\n"
             << "Some cardiovascular exercises that help in loosing weight are:\n"
             << "1. Running exercise\n"
             << "2. Walking exercise\n"
             << "3. Swimming exercise\n"
             << "Some sports exercises that help in loosing weight are:\n"
             << "1. Basketball exercise\n"
             << "2. Soccer exercise\n"
             << "3. Cricket exercise\n"
             << "Some core exercises that help in loosing weight are:\n"
             << "1. Weightlifting exercise\n"
             << "2. Planks exercise\n"
             << "3. Russian twists exercise\n"
             << " Some aerobics exercises that help in loosing weight are::\n"
             << "1. Rope jumping exercise\n"
             << "2. Rope skipping exercise\n"
             << "3. Dance aerobics exercise\n"
             << "\n\nBy following above given suggestions you can achieve your goal!\n"
             << endl;
    }
};

int User::UserID = 0;

int main()
{
    User users[max_user]; // Array to store users
    int userCount = 0;    // Number of users

    string choice;
    do
    {
        cout << "----------------------------" << endl;
        cout << "1. Sign Up\n2. Login\n3. Quit\n";
        cout << "----------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1")
        {
            string username, password, name;
            float height, weight;

            cout << "----------------------------" << endl;
            cout << "Enter username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter height (in m): ";
            cin >> height;
            cout << "Enter weight (in kg): ";
            cin >> weight;
            cout << "You're done with providing your information!\n";
            cout << "----------------------------" << endl;

            if (User::signup(users, userCount, username, password, name, height, weight))
            {
                cout << "Signup successful!\n";
            }
            else
            {
                cout << "Signup failed. User may already exist or maximum users reached.\n";
            }
        }
        else if (choice == "2")
        {
            string username, password;

            cout << "----------------------------" << endl;
            cin.ignore();
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            if (User::login(users, userCount, username, password))
            {
                if (User::login(users, userCount, username, password))
                {
                    // Login successful!
                    cout << "Login successful!\n";
                    cout << "----------------------------" << endl;

                    // Find the user in the array to access their data
                    int userIndex;
                    for (userIndex = 0; userIndex < userCount; userIndex++)
                    {
                        if (users[userIndex].getUsername() == username)
                        {
                            break;
                        }
                    }
                    // Read and update the user's data from the file
                    users[userIndex].updateUserDataFromFile(username);

                    // Display BMI

                    cout << "BMI: " << users[userIndex].calculateBMI() << endl;
                    if (users[userIndex].calculateBMI() < 18.5)
                    {
                        cout << "You are underweight!" << endl;
                        cout << "You should gain weight!" << endl;
                        cout << "----------------------------" << endl;
                    }
                    else if (users[userIndex].calculateBMI() >= 18.5 && users[userIndex].calculateBMI() <= 24.9)
                    {
                        cout << "You fall within healthy weight range!" << endl;
                        cout << "You do not need any diet plan!" << endl;
                        cout << "----------------------------" << endl;
                    }
                    else if (users[userIndex].calculateBMI() >= 25 && users[userIndex].calculateBMI() <= 29.9)
                    {
                        cout << "You are overweight!" << endl;
                        cout << "You should lose some weight!" << endl;
                        cout << "----------------------------" << endl;
                    }
                    else if (users[userIndex].calculateBMI() >= 30)
                    {
                        cout << "You are obese!" << endl;
                        cout << "You should lose weight!" << endl;
                        cout << "----------------------------" << endl;
                    }

                    // Performing other actions after login

                    string take_cal;
                    cout << "\n----------------------------" << endl;
                    cout << "Choose your goal :\n"
                         << "1. Gain Calories\n"
                         << "2. Lose Calories\n";
                    cout << "----------------------------" << endl;
                    cin >> take_cal;
                    if (take_cal == "1")
                    {
                        while (1)
                        {
                            int goal;
                            cout << "Enter amount of calories you want to gain: ";
                            cin >> goal;
                            if (goal > 2500 || goal < 0)
                            {
                                cout << "Enter a valid goal (within normal range i.e. 2500 calories)!" << endl;
                                continue;
                            }
                            else
                            {
                                gainfood f1;
                                f1.food_intake();
                                gainexercise e1;
                                e1.exercise_intake();
                                if (goal > (f1.getUser_cal() + e1.getUsercal()))
                                {
                                    cout << "----------------------------" << endl;
                                    cout << "\nYour goal: " << goal << "." << endl
                                         << "Calories gained: " << f1.getUser_cal() + e1.getUsercal() << "." << endl
                                         << "You have to gain " << goal - (f1.getUser_cal() + e1.getUsercal()) << " calories to achieve your goal!"
                                         << endl;
                                    cout << "----------------------------" << endl;

                                    string diet_plan;
                                    while (1)
                                    {
                                        cout << "----------------------------" << endl;
                                        cout << "Press 1 if you want a diet plan to acheive your goal or 2 to logout:" << endl;
                                        cin >> diet_plan;
                                        if (diet_plan == "1")
                                        {
                                            string plan;
                                            cout << "----------------------------" << endl;
                                            cout << "Press 1 if you want to follow a user's diet plan who achieved their goal and 2 to follow defualt diet plan:" << endl;
                                            cin >> plan;
                                            while (1)
                                            {
                                                if (plan == "1")
                                                {
                                                    //declaring directory and structure points
                                                    DIR *dr;
                                                    struct dirent *en;
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Gain Weight/");
                                                    if (dr)
                                                    {
                                                        int filecount = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                cout << ++filecount << ". " << en->d_name << endl; // print all directory name
                                                            }
                                                        }
                                                        closedir(dr); // close all directory
                                                    }
                                                    // asking user to choose a file
                                                    int choice;
                                                    cout << "----------------------------" << endl;
                                                    cout << "Enter the number of file you want to view to get diet plan: ";
                                                    cin >> choice;

                                                    // opening the selected file
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Gain Weight/");
                                                    if (dr)
                                                    {
                                                        int currentfile = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                currentfile++;
                                                                if (currentfile == choice)
                                                                {
                                                                    ifstream file("E:/OOP Project - Fitness Tracking System/Gain Weight/" + string(en->d_name));
                                                                    if (file.is_open())
                                                                    {
                                                                        string getplan;
                                                                        while (getline(file, getplan))
                                                                        {
                                                                            cout << getplan << endl;
                                                                        }
                                                                        file.close();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    cout << "Unable to open file!" << endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    closedir(dr);
                                                    break;
                                                }
                                                else if (plan == "2")
                                                {
                                                    dietPlan::loose_dietplan();
                                                    break;
                                                }
                                                else
                                                {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (diet_plan == "2") // logout
                                        {
                                            cout << "Logging out..." << endl;
                                            cout << "----------------------------" << endl;
                                            exit(0);
                                        }
                                        else
                                        {
                                            cout << "Choose a valid option!" << endl;
                                            continue;
                                        }
                                    }
                                }
                                else if (goal == (f1.getUser_cal() + e1.getUsercal()))
                                {
                                    cout << "----------------------------" << endl;
                                    cout << "You have achieved your goal!" << endl;
                                    cout << "----------------------------" << endl;
                                    // saving this user's diet plan to file so that it can be suggested to other users as well
                                    for (userIndex = 0; userIndex < userCount; userIndex++)
                                    {
                                        if (users[userIndex].getUsername() == username)
                                        {
                                            break;
                                        }
                                    }
                                    string filePath = "E:/OOP Project - Fitness Tracking System/Gain Weight/" + username;
                                    ofstream user(filePath + " diet plan", ios::out | ios::trunc); // if file exists already, it will erase previous diet plan and will add new one
                                    if (user.is_open())
                                    {
                                        user << "Food consumed by this user:" << endl
                                             << "Fried items:" << endl
                                             << "Nuggets eaten: " << f1.nuggetcount() << endl
                                             << "Rolls eaten: " << f1.rollcount() << endl
                                             << "Other fried items eaten: " << f1.other_friedcount() << endl
                                             << "Fruits:" << endl
                                             << "Bananas eaten: " << f1.bananacount() << endl
                                             << "Mangoes eaten: " << f1.mangocount() << endl
                                             << "Apples eaten: " << f1.applecount() << endl
                                             << "Other fruits eaten: " << f1.otherFruitcount() << endl
                                             << "Vegetables:" << endl
                                             << "Carrots eaten: " << f1.carrotcount() << endl
                                             << "Legumes eaten: " << f1.legumecount() << endl
                                             << "Cucumbers eaten: " << f1.cucumbercount() << endl
                                             << "Other vegetables consumed: " << f1.other_vegtcount() << endl
                                             << "Baked items:" << endl
                                             << "Pieces of cake consumed: " << f1.cakecount() << endl
                                             << "Cookies eaten: " << f1.cookiescount() << endl
                                             << "Breads eaten: " << f1.breadcount() << endl
                                             << "Other baked items eaten: " << f1.other_bakedcount() << endl;
                                        user << "Exercises performed by this user:" << endl
                                             << "Compound Exercises: " << endl
                                             << "Squats time: " << e1.squatstime() << " mins" << endl
                                             << "Deadlifts time: " << e1.deadlifts() << " mins" << endl
                                             << "Benchpress time: " << e1.benchpresstime() << " mins" << endl
                                             << "Other compound exercises time: " << e1.othercompund() << " mins" << endl
                                             << "Isolation Exercises: " << endl
                                             << "Biceps time: " << e1.bicpedumbelltime() << " mins" << endl
                                             << "Triceps time: " << e1.tricepdumbelltime() << " mins" << endl
                                             << "Lunges time: " << e1.lungestime() << " mins" << endl
                                             << "Other isolation exercises time: " << e1.otherisolationtime() << endl
                                             << "Weighted exercises:" << endl
                                             << "Weighted crunches time: " << e1.weightedcrunchestime() << " mins" << endl
                                             << "Weighted dips time: " << e1.weighteddipstime() << " mins" << endl
                                             << "Other weighted exercise time: " << e1.otherweightedtime() << endl
                                             << "Functional exercises: " << endl
                                             << "Kettle bell swings time: " << e1.kettlebelltime() << " mins" << endl
                                             << "Medicine bell time: " << e1.medicinebelltime() << " mins" << endl
                                             << "Other functional exercises time: " << e1.otherfunctionaltime() << endl;
                                        user.close();
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Error opening file!" << endl;
                                        break;
                                    }
                                }
                                else if (goal < (f1.getUser_cal() + e1.getUsercal()))
                                {
                                    cout << "----------------------------" << endl;
                                    cout << "\nYour goal: " << goal << "." << endl
                                         << "Calories gained: " << f1.getUser_cal() + e1.getUsercal() << "." << endl
                                         << "You have gained " << (f1.getUser_cal() + e1.getUsercal()) - goal << " calories more than your goal!"
                                         << endl
                                         << "You should loose extra calories to achieve you goal!"
                                         << endl;
                                    cout << "----------------------------" << endl;

                                    string diet_plan;
                                    while (1)
                                    {
                                        cout << "----------------------------" << endl;
                                        cout << "Press 1 if you want a diet plan to acheive your goal or 2 to logout:" << endl;
                                        cin >> diet_plan;
                                        if (diet_plan == "1")
                                        {
                                            string plan;
                                            cout << "----------------------------" << endl;
                                            cout << "Press 1 if you want to follow a user's diet plan who achieved their goal or 2 to follow defualt diet plan:" << endl;
                                            cin >> plan;
                                            while (1)
                                            {
                                                if (plan == "2")
                                                {
                                                    dietPlan::loose_dietplan();
                                                    break;
                                                }
                                                else if (plan == "1")
                                                {
                                                    DIR *dr;
                                                    struct dirent *en;
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Loose Weight/");
                                                    if (dr)
                                                    {
                                                        int filecount = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                cout << ++filecount << ". " << en->d_name << endl; // print all directory name
                                                            }
                                                        }
                                                        closedir(dr); // close all directory
                                                    }
                                                    // asking user to choose a file
                                                    int choice;
                                                    cout << "----------------------------" << endl;
                                                    cout << "Enter the number of file you want to view to get diet plan: ";
                                                    cout << "----------------------------" << endl;
                                                    cin >> choice;

                                                    // opening the selected file
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Loose Weight/");
                                                    if (dr)
                                                    {
                                                        int currentfile = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                currentfile++;
                                                                if (currentfile == choice)
                                                                {
                                                                    ifstream file("E:/OOP Project - Fitness Tracking System/Loose Weight/" + string(en->d_name));
                                                                    if (file.is_open())
                                                                    {
                                                                        string getplan;
                                                                        while (getline(file, getplan))
                                                                        {
                                                                            cout << getplan << endl;
                                                                        }
                                                                        file.close();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    cout << "Unable to open file!" << endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    closedir(dr);
                                                    break;
                                                }
                                                else
                                                {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (diet_plan == "2")
                                        {
                                            cout << "Logging out..." << endl;
                                            cout << "----------------------------" << endl;
                                            exit(0);
                                        }
                                        else
                                        {
                                            cout << "Choose a valid option!" << endl;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    else if (take_cal == "2")
                    {
                        int goal;
                        cout << "Enter amount of calories you want to loose: ";
                        cin >> goal;
                        while (1)
                        {
                            if (goal > 2500 || goal < 0)
                            {
                                cout << "Enter a valid goal (within normal range i.e. 2500 calories)!" << endl;
                                continue;
                            }
                            else
                            {
                                loosefood f1;
                                f1.food_intake();
                                LooseExercise e1;
                                e1.exerciseIntake();
                                if (goal > (f1.getUserCal() + e1.getusercal()))
                                {
                                    cout << "\nYour goal: " << goal << endl
                                         << "Calories lost: " << f1.getUserCal() + e1.getusercal() << "." << endl
                                         << "You have to loose " << goal - (f1.getUserCal() + e1.getusercal()) << " calories to achieve your goal."
                                         << endl;
                                    string diet_plan;
                                    while (1)
                                    {
                                        cout << "Press 1 if you want a diet plan to acheive your goal or 2 to logout:" << endl;
                                        cin >> diet_plan;
                                        if (diet_plan == "1")
                                        {
                                            string plan;
                                            cout << "Press 1 if you want to follow a user's diet plan who achieved their goal or 2 to follow defualt diet plan:" << endl;
                                            cin >> plan;
                                            while (1)
                                            {
                                                if (plan == "2")
                                                {
                                                    dietPlan::loose_dietplan();
                                                    break;
                                                }
                                                else if (plan == "1")
                                                {
                                                    DIR *dr;
                                                    struct dirent *en;
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Loose Weight/");
                                                    if (dr)
                                                    {
                                                        int filecount = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                cout << ++filecount << ". " << en->d_name << endl; // print all directory name
                                                            }
                                                        }
                                                        closedir(dr); // close all directory
                                                    }
                                                    // asking user to choose a file
                                                    int choice;
                                                    cout << "Enter the number of file you want to view to get diet plan: ";
                                                    cin >> choice;

                                                    // opening the selected file
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Loose Weight/");
                                                    if (dr)
                                                    {
                                                        int currentfile = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                currentfile++;
                                                                if (currentfile == choice)
                                                                {
                                                                    ifstream file("E:/OOP Project - Fitness Tracking System/Loose Weight/" + string(en->d_name));
                                                                    if (file.is_open())
                                                                    {
                                                                        string getplan;
                                                                        while (getline(file, getplan))
                                                                        {
                                                                            cout << getplan << endl;
                                                                        }
                                                                        file.close();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    cout << "Unable to open file!" << endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    closedir(dr);
                                                    break;
                                                }
                                                else
                                                {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (diet_plan == "2")
                                        {
                                            cout << "Logging out..." << endl;
                                            exit(0);
                                        }
                                        else
                                        {
                                            cout << "Choose a valid option!" << endl;
                                            continue;
                                        }
                                    }
                                }
                                else if (goal == (f1.getUserCal() + e1.getusercal()))
                                {
                                    cout << "You have achieved your goal." << endl;
                                    // saving this user's diet plan to file so that it can be suggested to other users as well
                                    for (userIndex = 0; userIndex < userCount; userIndex++)
                                    {
                                        if (users[userIndex].getUsername() == username)
                                        {
                                            break;
                                        }
                                    }
                                    string filePath = "E:/OOP Project - Fitness Tracking System/Loose Weight/" + username;
                                    ofstream userfile(filePath + " diet plan", ios::out | ios::trunc);
                                    if (userfile.is_open())
                                    {
                                        userfile << "Food consumed by this user:" << endl
                                                 << "Fruits consumed by this user:\n"
                                                 << "Peaches: " << f1.peachescount() << endl
                                                 << "Strawberries: " << f1.strawberrycount() << endl
                                                 << "Grapefruits: " << f1.grapefruitcount() << endl
                                                 << "Other fruits: " << f1.otherfruitcount() << endl
                                                 << "Fluids consumed: " << endl
                                                 << "Black coffee: " << f1.blackcoffeecount() << " cups" << endl
                                                 << "Green tea: " << f1.greenteacount() << " cups" << endl
                                                 << "Herbal tea: " << f1.herbalteacount() << " cups" << endl
                                                 << "Nuts & seeds consumed by this user:\n"
                                                 << "Almonds: " << f1.almondcount() << endl
                                                 << "Cashews: " << f1.cashewcount() << endl
                                                 << "Chia seeds: " << f1.chiacount() << endl
                                                 << "Other nuts and seeds consumed: " << f1.othernutcount() << endl
                                                 << "Vegetables consumed by this user: " << endl
                                                 << "Tomatoes: " << f1.tomatocount() << endl
                                                 << "Spinach: " << f1.spinachcount() << endl
                                                 << "Zucchini: " << f1.zucchinicount() << endl
                                                 << "Other vegetables consumed: " << f1.othervegtcount() << endl;
                                        userfile << "\nExercises performed by this user:\n"
                                                 << "Cardiovascular exercises:\n"
                                                 << "Running exercise: " << e1.RunningTime() << " mins" << endl
                                                 << "Walking exercise: " << e1.WalkingTime() << " mins" << endl
                                                 << "Swimming exercise: " << e1.SwimmingTime() << " mins" << endl
                                                 << "Other cardiovascular exercises time: " << e1.OtherCardioTime() << endl
                                                 << "Sports exercises: " << endl
                                                 << "Basketball exercise: " << e1.BasketballTime() << " mins" << endl
                                                 << "Soccer exercise: " << e1.SoccerTime() << " mins" << endl
                                                 << "Cricket exercise: " << e1.CricketTime() << " mins" << endl
                                                 << "Other sports time: " << e1.OtherSportsTime() << " mins" << endl
                                                 << "Core exercises:\n"
                                                 << "Weightlifting exercise: " << e1.WeightliftingTime() << " mins" << endl
                                                 << "Planks exercise: " << e1.PlanksTime() << " mins" << endl
                                                 << "Other core exercise time: " << e1.OtherCoreTime() << " mins" << endl
                                                 << "Russian twists exercise: " << e1.RussianTwistsTime() << " mins" << endl
                                                 << "Aerobics exercises: "
                                                 << "Rope jumping exercise: " << e1.RopeJumpingTime() << " mins" << endl
                                                 << "Rope skipping exercise: " << e1.RopeSkippingTime() << " mins" << endl
                                                 << "Dance aerobics exercises: " << e1.DanceAerobicsTime() << " mins" << endl
                                                 << "Other aerobic exercises: " << e1.OtherAerobicsTime() << " mins" << endl;
                                        userfile.close();
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Error opening file." << endl;
                                        break;
                                    }
                                }
                                else if (goal < (f1.getUserCal() + e1.getusercal()))
                                {
                                    cout << "\nYour goal: " << goal << endl
                                         << "Calories lost: " << f1.getUserCal() + e1.getusercal() << "." << endl
                                         << "You lost " << (f1.getUserCal() + e1.getusercal()) - goal << " calories more than your goal."
                                         << endl
                                         << "You should gain " << (f1.getUserCal() + e1.getusercal()) - goal << " calories to achieve your goal." << endl;

                                    string diet_plan;
                                    while (1)
                                    {
                                        cout << "Press 1 if you want a diet plan to acheive your goal or 2 to logout:" << endl;
                                        cin >> diet_plan;
                                        if (diet_plan == "1")
                                        {
                                            string plan;
                                            cout << "Press 1 if you want to follow a user's diet plan who achieved their goal or 2 to follow defualt diet plan:" << endl;
                                            cin >> plan;
                                            while (1)
                                            {
                                                if (plan == "2")
                                                {
                                                    dietPlan::loose_dietplan();
                                                    break;
                                                }
                                                else if (plan == "1")
                                                {
                                                    DIR *dr;
                                                    struct dirent *en;
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Loose Weight/");
                                                    if (dr)
                                                    {
                                                        int filecount = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                cout << ++filecount << ". " << en->d_name << endl; // print all directory name
                                                            }
                                                        }
                                                        closedir(dr); // close all directory
                                                    }
                                                    // asking user to choose a file
                                                    int choice;
                                                    cout << "Enter the number of file you want to view to get diet plan: ";
                                                    cin >> choice;

                                                    // opening the selected file
                                                    dr = opendir("E:/OOP Project - Fitness Tracking System/Loose Weight/");
                                                    if (dr)
                                                    {
                                                        int currentfile = 0;
                                                        while ((en = readdir(dr)) != NULL)
                                                        {
                                                            if (strcmp(en->d_name, ".") != 0 && strcmp(en->d_name, "..") != 0)
                                                            {
                                                                currentfile++;
                                                                if (currentfile == choice)
                                                                {
                                                                    ifstream file("E:/OOP Project - Fitness Tracking System/Loose Weight/" + string(en->d_name));
                                                                    if (file.is_open())
                                                                    {
                                                                        string getplan;
                                                                        while (getline(file, getplan))
                                                                        {
                                                                            cout << getplan << endl;
                                                                        }
                                                                        file.close();
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    cout << "Unable to open file!" << endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    closedir(dr);
                                                    break;
                                                }
                                                else
                                                {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (diet_plan == "2")
                                        {
                                            cout << "Logging out..." << endl;
                                            exit(0);
                                        }
                                        else
                                        {
                                            cout << "Choose a valid option!" << endl;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "Login failed. Invalid username or password.\n";
            }
        }
        else if (choice == "3")
        {
            cout << "Bye Bye :)" << endl;
            break;
        }
        else if (choice != "3")
        {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice == "1" || choice == "2" || choice == "3");
}