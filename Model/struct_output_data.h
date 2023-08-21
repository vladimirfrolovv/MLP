#ifndef CPP7_MLP_2_SRC_MODEL_STRUCT_OUTPUT_DATA_H_
#define CPP7_MLP_2_SRC_MODEL_STRUCT_OUTPUT_DATA_H_

typedef struct output_data_ {
  double average_accuracy_{}, precision{}, recall{}, f_measure{}, mse{};
  char answer{};
} output_data_;

#endif  // CPP7_MLP_2_SRC_MODEL_STRUCT_OUTPUT_DATA_H_