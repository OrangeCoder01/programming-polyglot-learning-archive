library ieee;
use ieee.std_logic_1164.all;

entity en_half_adder is
    port
    (
        a, b: in std_logic;
        sum, c_out: out std_logic
    );
end entity en_half_adder;

architecture ar_half_adder of en_half_adder is
    begin
        sum <= a xor b;
        c_out <= a and b;

end architecture ar_half_adder;