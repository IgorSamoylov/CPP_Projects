
#include "Solution.h"


int main()
{
    //Solution0 solution;
    SolutionBest solution;
    string s = "barfoofoobarthefoobarman";
    vector<string> words { "bar","foo","the" };

    vector<int> output = solution.findSubstring(s, words);

    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; }); 

    cout << "Second" << endl;

    s = "barfoothefoobarman";
    words = { "foo","bar" };
    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Third" << endl;
    
    s = "wordgoodgoodgoodbestword";
    words = { "word", "good", "best", "word" };

    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Fourth" << endl;
    
    s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    words = { "fooo", "barr", "wing", "ding", "wing" };

    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Fives" << endl;

    s = "a";
    words = { "a" };

    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Six" << endl;

    s = "aaa";
    words = { "a", "a" };

    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Seven" << endl;
    
    s = "aaaaaaaaaaaaaa";
    words = { "aa", "aa" };

    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Eight" << endl;
   
    s = "bcabbcaabbccacacbabccacaababcbb";
    words = { "c", "b", "a", "c", "a", "a", "a", "b", "c" };

    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });


    cout << "Nine" << endl;
    
    s = "dlmogiklbqfggokuonfgugiyammwvwhbjvrqgdbjtipcwzwmobtjjdhmpvknrsqbpjtvmwfifukbwgokjjvvmeheatttljwdupygofotcywygmksvipkmyqmrjifueiouiukoldqlzquocojkdvzdlnuuvbqajewubgiolazmsvaujmfohervtorppipbolvrtdfefhqxcrrofycmewjykbnzjeazrxrkayohfgekzwyewctbyczidokoskojihvkflslryxruvxrzquytvgyjsndddmnkhzrstclsbeowchwsbwnwemhxbkcgwpqfqjzmmlenpumrckmdgzcmnjjqulwscoytyxhkklzahntjzfphhruwadnwpjptypmwovizijzqzuzycogjhahkdugugxoemccbymagvbyuxytzobkwbsigoobuoraatedrqfamiyigydhpeslhmvoajrxzixabcfvslxgvvpbwujlzdygptureloetogxslsmyrtuokxkeivflvmcoiutwkzryfoqsidtzypqkmaqxywktknisjdoteisjykdhpyipnyzcbqzzolsyycsjfjdjrxupjayzyhqohqqiirjyccwdgoomxtxqqugcwedwntkxlcfvvrtatpfbgtnfnnwfjchfikdwgotrsanorgqmyvoeqdldshldlsiufoslencwprmhyevwzlcqrpvlzgpkbzggnytrnxqdpekpjhnivraogwzfeoqfoynbzgvmelpvpbkyjxjgojuwhtcmkurysfbrnwerjvozxazixionukkbfonpihpcorwbpcvzxjaukzejksxeejhkxxzhgpjuihvxjqyhaydmaivkcuqhdztcyulelvyteutokrxmscasmwepswyyxrawnmazjbsnvndhfcwzfwrruxinvilsbnopbroksiapwfydkwcptvipstepbphffyugrktlsvaqaatkxxbssmhmhmbidjpijjravklofnghnaumxvesjoeqcibhtqsccjextpnaeuhtwdgvbknkaubccemvuezyndwiujkyftrbxxzykmkkilpkrdhohgmwjigduqdbjvdgueggqrtbeknwnvkubysnjysdowgztjipnowghpjmbwkorwkvuckfaciqaprvazlqqjyxahlbdxpxvzusdexfiivlzogbotrgerfeathgqydmxzgcddhnleykthmjcfphzwnzpvfgtkutjavoffcrjcdejrpoxevydkxsffabruwbwtrcytvkyyqhqgvpmsnpdmiktinlflmdffffzcrxbigtqeicyxudlcofmdqtpexwjebkhtjidsdtwlvwkpavtqaitsbkyagifiumdewgwzzumwqyoqtjgwrcqvmpvtzadtogxmmvnlrzjixxathjpylhvzwruvtxpkdowrmkedlonjloeuxtvkcqjzjeuddlnhalamvfrhvfsitwdsryetqnu";
    words = { "pbolvrtdfefhqxcrrofyc", "mewjykbnzjeazrxrkayoh", "fgekzwyewctbyczidokos", "kojihvkflslryxruvxrzq", "uytvgyjsndddmnkhzrstc", "lsbeowchwsbwnwemhxbkc", "gwpqfqjzmmlenpumrckmd", "gzcmnjjqulwscoytyxhkk", "lzahntjzfphhruwadnwpj", "ptypmwovizijzqzuzycog", "jhahkdugugxoemccbymag", "vbyuxytzobkwbsigoobuo", "raatedrqfamiyigydhpes", "lhmvoajrxzixabcfvslxg", "vvpbwujlzdygptureloet", "ogxslsmyrtuokxkeivflv", "mcoiutwkzryfoqsidtzyp", "qkmaqxywktknisjdoteis", "jykdhpyipnyzcbqzzolsy", "ycsjfjdjrxupjayzyhqoh", "qqiirjyccwdgoomxtxqqu", "gcwedwntkxlcfvvrtatpf", "bgtnfnnwfjchfikdwgotr", "sanorgqmyvoeqdldshldl", "siufoslencwprmhyevwzl", "cqrpvlzgpkbzggnytrnxq" };

    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Ten" << endl;
    s = "cccbcacaa";
    words = { "cc", "bc" };
    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });

    cout << "Eleven" << endl;
    s = "faoucbmnvdujheznbntaszqsxicczlagnqbrsnfptbycfapjnkjflbzilemkpotehwvblcsefqgnsxwgkhnvjpgutuhklcosylvjonqtfyiyyegimtfxilrdiantcdncpiofxgaegjcenkobguyqhsupsjkxnxbehrjgxjlespiiazjiviyeaswuegtrexxnogumrfskwcuwbfgynfdpzzmdfhwletbvbvjtcbfydbxhgdfuiilkhznpjmcnhdkjytecujbykafqdkmovaacbntkbwyjziuaeycyhfytfdllqybnabpbqlmujmdiwxkaxnzeuxzcdknvkqimtzojkcdtoiemhonedokanjcswpnihvvaxlljprdfzjrhzgnfwyfkjhchyssfppfmaqwrjbwjmnslwhqsfverejacbshshohjhdaqgwzsmtfkbycitjzasccvukpcywlhboyjkzdyvjiwhngcwicqkhnercgrzuzcizmuyptvadrhqymmgqeqxrwqwfivzjzjklfkbygbczlszzhfpnxpfwfdbpacazlklqxordrveepedwlvmjktfrwihwkjvvugntweyqzcupgynstzdfskwqsfmcpixlqmenrcfsezjlxzdsyiztswjkdymsgldwxhlqlqjqsudptikuqjpihyslwgderjdqsqhejswbmzqihcczorhvrbiqhouaxxqroxvxrragssozvqajhhgakrqrfltekkvajtzbkzhfsvepnfawoiwzznsgammmykphdoipqrukobzbizxyhuxjjsrjgexgomntbyktphdekchsdfqmbqxkkpvstsyjfleilqbdxgjhkqbnvsbwkzguodmjwkubxaljqomouvxelztjtwhdvqzltlwpxssusffjtrznowtavmlojstgisuefsvclozdteopwnckmwmjkzavstecoyitsewduvjpzzexnjkbhykrympsitwwtfpllnrfiaukzzjoivrrueisqxmysiulpmzazqfkqcwrbfilbzcxfmrwmdwelrsbfrdehjqznmsquabxcfuhtlfhqcmbvgeaxkggvxfilxyfabecgalbnrjdtxhodnqcxwisvpahmyomztqhveljvumotteyhuagskzozbxlclabgslcwylruzhnvnlejnkcxlswnpjrajsjefnadauxzbmwrzaamnclauhplrgocbxggkjmkdllgykzzkamzcxazhpkywycxxlfhuttzfhhfrhedjqfnqfmxwzxuxztxmzgischzjrecajhjbmwrtlqqknmjpgg";
    words = { "mntbyktphdekchsdfqmbq", "zznsgammmykphdoipqruk", "hyssfppfmaqwrjbwjmnsl", "hkqbnvsbwkzguodmjwkub", "qsqhejswbmzqihcczorhv", "xaljqomouvxelztjtwhdv", "dptikuqjpihyslwgderjd", "sozvqajhhgakrqrfltekk", "lszzhfpnxpfwfdbpacazl", "tavmlojstgisuefsvcloz", "wjkdymsgldwxhlqlqjqsu", "dteopwnckmwmjkzavstec", "obzbizxyhuxjjsrjgexgo", "rwqwfivzjzjklfkbygbcz", "whngcwicqkhnercgrzuzc", "frwihwkjvvugntweyqzcu", "rbiqhouaxxqroxvxrrags", "qmenrcfsezjlxzdsyizts", "cvukpcywlhboyjkzdyvji", "xkkpvstsyjfleilqbdxgj", "ykrympsitwwtfpllnrfia", "daqgwzsmtfkbycitjzasc", "whqsfverejacbshshohjh", "oyitsewduvjpzzexnjkbh", "izmuyptvadrhqymmgqeqx", "klqxordrveepedwlvmjkt", "qzltlwpxssusffjtrznow", "pgynstzdfskwqsfmcpixl", "vajtzbkzhfsvepnfawoiw" };
    output = solution.findSubstring(s, words);
    for_each(output.begin(), output.end(), [](int n) { cout << n << " " << endl; });
}

