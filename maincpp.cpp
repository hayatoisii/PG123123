#include <iostream>

/*クラス名「TemplateClass」で複数クラステンプレートを定義*/
template <typename Type, typename Type2>
class TemplateClass {
public:
    // コンストラクタ（メンバ変数Number1,Number2を引数number1,number2で初期化）
    TemplateClass(Type number1, Type2 number2) :
        Number1(number1), Number2(number2) {
    }

    Type Min()
    {
        if (Number1 < Number2) // Number1よりNumber2が小さかったら
        {
            return static_cast<Type>(Number1);
        }
        else {
            return static_cast<Type>(Number2);
        }
    }

private:
    /*Type,Type2を使ってNumber1と2を定義*/
    Type Number1;
    Type2 Number2;
};


int main() {

    /*クラス名から型を考えて<>の中を定義*/
    TemplateClass<int, float> intFloatTemplate(10, 50.0f);
    TemplateClass<int, double> intDoubleTemplate(80, 13.0);
    TemplateClass<float, int> floatIntTemplate(2.0f, 9);
    TemplateClass<float, double> floatDoubleTemplate(11.0f, 3.5);
    TemplateClass<double, int> doubleIntTemplate(666.0, 333);
    TemplateClass<double, float> doubleFloatTemplate(435.8, 563.5f);

    std::cout << "int(10)　と float(50.0f) を比べて小さい数字を表す：" << intFloatTemplate.Min() << std::endl;
    std::cout << "int(80)　と double(13.0) を比べて小さい数字を表す：" << intDoubleTemplate.Min() << std::endl;
    std::cout << "float(2.0f)　と int(9) を比べて小さい数字を表す：" << floatIntTemplate.Min() << std::endl;
    std::cout << "float(11.0f)　と double(3.5) を比べて小さい数字を表す：" << floatDoubleTemplate.Min() << std::endl;
    std::cout << "double(666.0)　と int(333) を比べて小さい数字を表す：" << doubleIntTemplate.Min() << std::endl;
    std::cout << "double(435.8)　と float(563.5) を比べて小さい数字を表す：" << doubleFloatTemplate.Min() << std::endl;

    return 0;
}