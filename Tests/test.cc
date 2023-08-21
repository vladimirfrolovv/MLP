#include <gtest/gtest.h>

#include "../Controller/controller.h"


TEST(ModelTests, Case1) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", false);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0862745, 0.152941, 0.396078, 0.666667,
            0.772549, 0.741176, 0.286275, 0.0156863, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0.0235294, 0.25098, 0.666667, 0.831373, 0.94902, 0.996078,
            1, 1, 0.964706, 0.431373, 0.0313726, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.247059, 0.992157, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 0.988235, 0.929412, 0.14902, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0.298039, 0.992157, 1, 1, 1, 0.992157, 0.968628, 0.835294,
            0.72549, 0.854902, 1, 1, 1, 1, 0.980392, 0.0862745, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0156863, 0.972549, 1, 1, 0.952941, 0.164706, 0, 0, 0,
            0, 0, 0.0901961, 0.545098, 1, 1, 1, 0.717647, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.168627, 1, 1, 0.980392, 0.6, 0, 0, 0, 0,
            0, 0, 0, 0.0156863, 0.831373, 1, 1, 0.901961, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0627451, 0.713726, 1, 1, 0.301961, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.164706, 0.788235, 1, 0.996078, 0.054902, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.301961, 0.972549, 1, 0.984314, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0666667, 0.682353, 1, 1, 0.137255, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.545098, 0.988235, 1, 0.854902, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.27451, 0.937255, 1, 0.996078, 0.054902, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.615686, 0.996078, 1, 0.815686, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.227451, 0.996078, 1, 1, 0.886275, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.619608, 0.996078, 1, 0.835294, 0, 0, 0, 0, 0, 0,
            0, 0, 0.0235294, 0.815686, 1, 1, 1, 0.54902, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.505882, 0.980392, 1, 0.921569, 0, 0, 0, 0, 0, 0,
            0.00784314, 0.239216, 0.890196, 1, 1, 1, 0.756863, 0.00784314, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.231373, 0.901961, 1, 0.996078, 0.0627451, 0.0392157, 0.12549, 0.145098, 0.517647, 0.890196,
            0.972549, 1, 1, 1, 0.980392, 0.643137, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0156863, 0.305882, 1, 0.988235, 0.992157, 1, 1, 1, 1, 1,
            1, 1, 1, 0.85098, 0.0588235, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.67451, 0.917647, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 0.996078, 0.984314, 0.835294, 0.698039, 0.117647, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.12549, 0.976471, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 0.713726, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.0627451, 0.956863, 1, 0.984314, 0.992157, 0.909804, 0.866667, 0.823529, 0.819608, 0.811765, 0.870588,
            0.92549, 0.972549, 0.996078, 1, 1, 1, 1, 0.113725, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0705882, 0.121569, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0.0705882, 0.298039, 0.898039, 0.984314, 0.839216, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0313726, 0.00784314, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'A');
}
TEST(ModelTests, Case2) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", false);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0.823529, 0.176471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 0.533333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.984314, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.0784314, 0,
            0, 0, 0, 0.690196, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
            0, 0, 0.0901961, 1, 1, 1, 1, 1, 1, 1, 0.431373, 0.509804, 0.121569, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0.121569, 0, 0, 0,
            0, 0, 1, 1, 1, 1, 0.00784314, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 0.494118, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 0.235294, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 0.976471, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.929412, 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'F');
}
TEST(ModelTests, Case3) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", false);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0.733333, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
            1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
            1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0.988235,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.188235, 1, 1, 1, 1, 0.109804, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 0.8, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0.431373, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0.266667, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.333333, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0.262745, 1, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0901961, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0.541176, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'M');
}
TEST(ModelTests, Case4) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", false);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0.00392157, 0.00784314, 0.00392157, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0156863, 0.0627451, 0.105882, 0.105882, 0.0705882, 0.0392157, 0.0156863, 0.00392157, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0117647, 0.0941177, 0.305882, 0.498039, 0.513726, 0.419608, 0.301961, 0.196078, 0.105882, 0.0588235,
            0.027451, 0.0117647, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.027451, 0.207843, 0.686275, 0.945098, 0.941177, 0.905882, 0.811765, 0.686275, 0.52549, 0.364706,
            0.235294, 0.145098, 0.0745098, 0.027451, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.027451, 0.219608, 0.709804, 0.968628, 0.996078, 0.996078, 0.988235, 0.972549, 0.937255, 0.854902,
            0.745098, 0.596078, 0.415686, 0.247059, 0.133333, 0.0705882, 0.0509804, 0.027451, 0.00392157, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0117647, 0.105882, 0.368627, 0.635294, 0.796079, 0.894118, 0.952941, 0.980392, 0.992157, 0.992157,
            0.984314, 0.956863, 0.882353, 0.741176, 0.584314, 0.478431, 0.368627, 0.203922, 0.0627451, 0.00784314, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0235294, 0.0823529, 0.184314, 0.294118, 0.419608, 0.576471, 0.729412, 0.85098, 0.92549,
            0.972549, 0.992157, 1, 0.980392, 0.960784, 0.94902, 0.890196, 0.643137, 0.227451, 0.0313726, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00392157, 0.0117647, 0.0196078, 0.0470588, 0.0862745, 0.14902, 0.247059, 0.384314, 0.552941,
            0.721569, 0.866667, 0.956863, 0.992157, 1, 1, 0.996078, 0.905882, 0.372549, 0.0509804, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0.00784314, 0.0352941, 0.0901961, 0.176471, 0.333333,
            0.533333, 0.760784, 0.921569, 0.984314, 1, 1, 0.988235, 0.827451, 0.313726, 0.0392157, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.0117647, 0.0392157, 0.109804, 0.223529, 0.368627, 0.552941, 0.733333,
            0.882353, 0.956863, 0.992157, 1, 0.980392, 0.929412, 0.772549, 0.447059, 0.12549, 0.0117647, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00392157, 0.0392157, 0.117647, 0.294118, 0.505882, 0.713726, 0.858824, 0.937255, 0.976471,
            0.996078, 0.992157, 0.960784, 0.87451, 0.701961, 0.486275, 0.258824, 0.101961, 0.0235294, 0.00392157, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0352941, 0.2, 0.509804, 0.796079, 0.937255, 0.984314, 0.992157, 0.992157, 0.980392,
            0.941177, 0.819608, 0.631373, 0.403922, 0.219608, 0.0901961, 0.0313726, 0.00784314, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00784314, 0.113725, 0.521569, 0.905882, 0.996078, 0.996078, 0.988235, 0.952941, 0.882353, 0.737255,
            0.572549, 0.34902, 0.184314, 0.0784314, 0.0313726, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0117647, 0.172549, 0.698039, 1, 1, 0.996078, 0.976471, 0.913726, 0.803922, 0.627451,
            0.431373, 0.266667, 0.137255, 0.0705882, 0.027451, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00784314, 0.121569, 0.568627, 0.933333, 0.992157, 1, 1, 0.992157, 0.968628, 0.921569,
            0.823529, 0.698039, 0.533333, 0.364706, 0.223529, 0.12549, 0.0627451, 0.0352941, 0.00784314, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0431373, 0.235294, 0.529412, 0.745098, 0.839216, 0.898039, 0.956863, 0.988235, 0.996078,
            0.988235, 0.976471, 0.945098, 0.858824, 0.717647, 0.584314, 0.439216, 0.27451, 0.105882, 0.0196078, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00784314, 0.0392157, 0.113725, 0.215686, 0.313726, 0.423529, 0.580392, 0.752941, 0.878431,
            0.945098, 0.980392, 0.996078, 0.996078, 0.988235, 0.960784, 0.917647, 0.788235, 0.380392, 0.0745098, 0.00784314, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.00784314, 0.0235294, 0.0470588, 0.0745098, 0.145098, 0.25098, 0.4,
            0.580392, 0.737255, 0.882353, 0.94902, 0.992157, 0.996078, 1, 0.988235, 0.654902, 0.14902, 0.0117647, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.00392157, 0.027451, 0.0901961, 0.2,
            0.32549, 0.521569, 0.737255, 0.905882, 0.980392, 0.996078, 1, 0.976471, 0.623529, 0.141176, 0.0117647, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0.00392157, 0.0235294, 0.0745098, 0.184314, 0.360784, 0.568627,
            0.729412, 0.87451, 0.956863, 0.984314, 0.996078, 0.988235, 0.917647, 0.717647, 0.317647, 0.0666667, 0.00392157, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0.0117647, 0.0352941, 0.0980392, 0.203922, 0.392157, 0.627451, 0.835294, 0.94902,
            0.984314, 1, 0.988235, 0.964706, 0.901961, 0.733333, 0.478431, 0.243137, 0.0745098, 0.0156863, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0117647, 0.0705882, 0.207843, 0.419608, 0.647059, 0.835294, 0.952941, 0.988235, 1,
            0.984314, 0.941177, 0.847059, 0.694118, 0.482353, 0.270588, 0.121569, 0.0392157, 0.00784314, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0470588, 0.247059, 0.619608, 0.87451, 0.964706, 0.988235, 0.996078, 0.968628, 0.870588,
            0.737255, 0.54902, 0.368627, 0.211765, 0.0980392, 0.0392157, 0.00784314, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0745098, 0.407843, 0.901961, 0.988235, 0.992157, 0.960784, 0.854902, 0.662745, 0.423529,
            0.239216, 0.121569, 0.0588235, 0.0235294, 0.00392157, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0627451, 0.317647, 0.729412, 0.862745, 0.788235, 0.603922, 0.388235, 0.203922, 0.0823529,
            0.0352941, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0196078, 0.109804, 0.270588, 0.34902, 0.282353, 0.164706, 0.0745098, 0.0235294, 0.00784314,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00392157, 0.0156863, 0.0392157, 0.0509804, 0.0392157, 0.0156863, 0.00392157, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'W');
}

TEST(ModelTests, Case5) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", true);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0862745, 0.152941, 0.396078, 0.666667,
            0.772549, 0.741176, 0.286275, 0.0156863, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0.0235294, 0.25098, 0.666667, 0.831373, 0.94902, 0.996078,
            1, 1, 0.964706, 0.431373, 0.0313726, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.247059, 0.992157, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 0.988235, 0.929412, 0.14902, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0.298039, 0.992157, 1, 1, 1, 0.992157, 0.968628, 0.835294,
            0.72549, 0.854902, 1, 1, 1, 1, 0.980392, 0.0862745, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0156863, 0.972549, 1, 1, 0.952941, 0.164706, 0, 0, 0,
            0, 0, 0.0901961, 0.545098, 1, 1, 1, 0.717647, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.168627, 1, 1, 0.980392, 0.6, 0, 0, 0, 0,
            0, 0, 0, 0.0156863, 0.831373, 1, 1, 0.901961, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0627451, 0.713726, 1, 1, 0.301961, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.164706, 0.788235, 1, 0.996078, 0.054902, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.301961, 0.972549, 1, 0.984314, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0666667, 0.682353, 1, 1, 0.137255, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.545098, 0.988235, 1, 0.854902, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.27451, 0.937255, 1, 0.996078, 0.054902, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.615686, 0.996078, 1, 0.815686, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.227451, 0.996078, 1, 1, 0.886275, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.619608, 0.996078, 1, 0.835294, 0, 0, 0, 0, 0, 0,
            0, 0, 0.0235294, 0.815686, 1, 1, 1, 0.54902, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.505882, 0.980392, 1, 0.921569, 0, 0, 0, 0, 0, 0,
            0.00784314, 0.239216, 0.890196, 1, 1, 1, 0.756863, 0.00784314, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.231373, 0.901961, 1, 0.996078, 0.0627451, 0.0392157, 0.12549, 0.145098, 0.517647, 0.890196,
            0.972549, 1, 1, 1, 0.980392, 0.643137, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0156863, 0.305882, 1, 0.988235, 0.992157, 1, 1, 1, 1, 1,
            1, 1, 1, 0.85098, 0.0588235, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.67451, 0.917647, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 0.996078, 0.984314, 0.835294, 0.698039, 0.117647, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.12549, 0.976471, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 0.713726, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.0627451, 0.956863, 1, 0.984314, 0.992157, 0.909804, 0.866667, 0.823529, 0.819608, 0.811765, 0.870588,
            0.92549, 0.972549, 0.996078, 1, 1, 1, 1, 0.113725, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0705882, 0.121569, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0.0705882, 0.298039, 0.898039, 0.984314, 0.839216, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0313726, 0.00784314, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'A');
}
TEST(ModelTests, Case6) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", true);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0.823529, 0.176471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 0.533333, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.984314, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.0784314, 0,
            0, 0, 0, 0.690196, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
            0, 0, 0.0901961, 1, 1, 1, 1, 1, 1, 1, 0.431373, 0.509804, 0.121569, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0.121569, 0, 0, 0,
            0, 0, 1, 1, 1, 1, 0.00784314, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 0.494118, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 0.235294, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 1, 0.976471, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0.929412, 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'F');
}
TEST(ModelTests, Case7) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", false);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0.733333, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
            1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
            1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0.988235,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.188235, 1, 1, 1, 1, 0.109804, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 0.8, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0.431373, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0.266667, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.333333, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0.262745, 1, 1, 1, 1, 1, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0901961, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 0.541176, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'M');
}
TEST(ModelTests, Case8) {
    s21::Controller *controller =s21::Controller::GetInstance();
    controller->LoadWeights("Weights/weight_for_test.txt", false);

    std::vector<float> picture = {
            0, 0, 0, 0, 0, 0, 0, 0.00392157, 0.00784314, 0.00392157, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0156863, 0.0627451, 0.105882, 0.105882, 0.0705882, 0.0392157, 0.0156863, 0.00392157, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0117647, 0.0941177, 0.305882, 0.498039, 0.513726, 0.419608, 0.301961, 0.196078, 0.105882, 0.0588235,
            0.027451, 0.0117647, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.027451, 0.207843, 0.686275, 0.945098, 0.941177, 0.905882, 0.811765, 0.686275, 0.52549, 0.364706,
            0.235294, 0.145098, 0.0745098, 0.027451, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.027451, 0.219608, 0.709804, 0.968628, 0.996078, 0.996078, 0.988235, 0.972549, 0.937255, 0.854902,
            0.745098, 0.596078, 0.415686, 0.247059, 0.133333, 0.0705882, 0.0509804, 0.027451, 0.00392157, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0117647, 0.105882, 0.368627, 0.635294, 0.796079, 0.894118, 0.952941, 0.980392, 0.992157, 0.992157,
            0.984314, 0.956863, 0.882353, 0.741176, 0.584314, 0.478431, 0.368627, 0.203922, 0.0627451, 0.00784314, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0235294, 0.0823529, 0.184314, 0.294118, 0.419608, 0.576471, 0.729412, 0.85098, 0.92549,
            0.972549, 0.992157, 1, 0.980392, 0.960784, 0.94902, 0.890196, 0.643137, 0.227451, 0.0313726, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00392157, 0.0117647, 0.0196078, 0.0470588, 0.0862745, 0.14902, 0.247059, 0.384314, 0.552941,
            0.721569, 0.866667, 0.956863, 0.992157, 1, 1, 0.996078, 0.905882, 0.372549, 0.0509804, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0.00784314, 0.0352941, 0.0901961, 0.176471, 0.333333,
            0.533333, 0.760784, 0.921569, 0.984314, 1, 1, 0.988235, 0.827451, 0.313726, 0.0392157, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.0117647, 0.0392157, 0.109804, 0.223529, 0.368627, 0.552941, 0.733333,
            0.882353, 0.956863, 0.992157, 1, 0.980392, 0.929412, 0.772549, 0.447059, 0.12549, 0.0117647, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00392157, 0.0392157, 0.117647, 0.294118, 0.505882, 0.713726, 0.858824, 0.937255, 0.976471,
            0.996078, 0.992157, 0.960784, 0.87451, 0.701961, 0.486275, 0.258824, 0.101961, 0.0235294, 0.00392157, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0352941, 0.2, 0.509804, 0.796079, 0.937255, 0.984314, 0.992157, 0.992157, 0.980392,
            0.941177, 0.819608, 0.631373, 0.403922, 0.219608, 0.0901961, 0.0313726, 0.00784314, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00784314, 0.113725, 0.521569, 0.905882, 0.996078, 0.996078, 0.988235, 0.952941, 0.882353, 0.737255,
            0.572549, 0.34902, 0.184314, 0.0784314, 0.0313726, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.0117647, 0.172549, 0.698039, 1, 1, 0.996078, 0.976471, 0.913726, 0.803922, 0.627451,
            0.431373, 0.266667, 0.137255, 0.0705882, 0.027451, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00784314, 0.121569, 0.568627, 0.933333, 0.992157, 1, 1, 0.992157, 0.968628, 0.921569,
            0.823529, 0.698039, 0.533333, 0.364706, 0.223529, 0.12549, 0.0627451, 0.0352941, 0.00784314, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0431373, 0.235294, 0.529412, 0.745098, 0.839216, 0.898039, 0.956863, 0.988235, 0.996078,
            0.988235, 0.976471, 0.945098, 0.858824, 0.717647, 0.584314, 0.439216, 0.27451, 0.105882, 0.0196078, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00784314, 0.0392157, 0.113725, 0.215686, 0.313726, 0.423529, 0.580392, 0.752941, 0.878431,
            0.945098, 0.980392, 0.996078, 0.996078, 0.988235, 0.960784, 0.917647, 0.788235, 0.380392, 0.0745098, 0.00784314, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0.00784314, 0.0235294, 0.0470588, 0.0745098, 0.145098, 0.25098, 0.4,
            0.580392, 0.737255, 0.882353, 0.94902, 0.992157, 0.996078, 1, 0.988235, 0.654902, 0.14902, 0.0117647, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.00392157, 0.027451, 0.0901961, 0.2,
            0.32549, 0.521569, 0.737255, 0.905882, 0.980392, 0.996078, 1, 0.976471, 0.623529, 0.141176, 0.0117647, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0.00392157, 0.0235294, 0.0745098, 0.184314, 0.360784, 0.568627,
            0.729412, 0.87451, 0.956863, 0.984314, 0.996078, 0.988235, 0.917647, 0.717647, 0.317647, 0.0666667, 0.00392157, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0.0117647, 0.0352941, 0.0980392, 0.203922, 0.392157, 0.627451, 0.835294, 0.94902,
            0.984314, 1, 0.988235, 0.964706, 0.901961, 0.733333, 0.478431, 0.243137, 0.0745098, 0.0156863, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0117647, 0.0705882, 0.207843, 0.419608, 0.647059, 0.835294, 0.952941, 0.988235, 1,
            0.984314, 0.941177, 0.847059, 0.694118, 0.482353, 0.270588, 0.121569, 0.0392157, 0.00784314, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0470588, 0.247059, 0.619608, 0.87451, 0.964706, 0.988235, 0.996078, 0.968628, 0.870588,
            0.737255, 0.54902, 0.368627, 0.211765, 0.0980392, 0.0392157, 0.00784314, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0745098, 0.407843, 0.901961, 0.988235, 0.992157, 0.960784, 0.854902, 0.662745, 0.423529,
            0.239216, 0.121569, 0.0588235, 0.0235294, 0.00392157, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0.00392157, 0.0627451, 0.317647, 0.729412, 0.862745, 0.788235, 0.603922, 0.388235, 0.203922, 0.0823529,
            0.0352941, 0.00784314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.0196078, 0.109804, 0.270588, 0.34902, 0.282353, 0.164706, 0.0745098, 0.0235294, 0.00784314,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0.00392157, 0.0156863, 0.0392157, 0.0509804, 0.0392157, 0.0156863, 0.00392157, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    controller->TestOneLetter(picture);
    char res = controller->GetAnswer();
    ASSERT_EQ(res, 'W');
}
