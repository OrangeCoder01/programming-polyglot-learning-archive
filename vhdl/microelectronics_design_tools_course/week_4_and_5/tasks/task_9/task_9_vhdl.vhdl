library ieee;
use ieee.std_logic_1164.all;

entity en_logic_alu is
    port
    (
        input_op_code: in std_logic_vector(1 downto 0);
        input_operand_1, input_operand_2: std_logic_vector(3 downto 0);
        output_result: out std_logic_vector(3 downto 0)
    );
end entity en_logic_alu;

architecture ar_logic_alu of en_logic_alu is
    begin
        with (input_op_code) select
            output_result <= (input_operand_1 and input_operand_2) when "00",
                             (input_operand_1 or input_operand_2) when "01",
                             (input_operand_1 xor input_operand_2) when "10",
                             (not input_operand_1) when "11",
                             (others => '0') when others; 
end architecture ar_logic_alu;