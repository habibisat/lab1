module OneBitAdder (
  // Inputs.
  input x,
  input y,
  input carry_in,

  // Outputs.
  output sum, output carry_out
);
    // Description of the logic goes here.
    wire x_not;
    wire y_not;
    wire carry_in_not;
    wire i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;

    assign x_not = ~x;
    assign y_not = ~y;
    assign carry_in_not = ~carry_in;

    // Let's describe circuit for sum.
    assign i1 = x_not & y_not;
    assign i5 = carry_in & i1;

    assign i2 = x_not & y;
    assign i6 = carry_in_not & i2;

    //assign i3 = x_not & y;
    assign i3 = x & y_not;
    assign i7 = carry_in_not & i3;

    assign i4 = x & y;
    assign i8 = carry_in & i4;

    assign i9 = i5 | i6;
    assign i10 = i7 | i8;

    assign sum = i9 | i10;

    // Carry out description.
    assign carry_out = (x & carry_in) | (y & carry_in) | (x & y);

endmodule
