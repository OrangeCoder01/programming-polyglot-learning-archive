library ieee;
use ieee.std_logic_1164.all;

-- 2-input XNOR gate entity
entity xnor2 is
    port 
    (
        in1, in2 : in  std_logic;
        out1     : out std_logic
    );
end xnor2;

architecture dataflow of xnor2 is
begin
    out1 <= in1 xnor in2;
end dataflow;

--------------------------------------------------

-- 3-input AND gate entity
library ieee;
use ieee.std_logic_1164.all;

entity and3 is
    port 
    (
        in1, in2, in3 : in  std_logic;
        out1          : out std_logic
    );
end and3;

architecture dataflow of and3 is
begin
    out1 <= in1 and in2 and in3;
end dataflow;

--------------------------------------------------

-- Top-level 3-bit comparator
library ieee;
use ieee.std_logic_1164.all;

entity my_compare is
    port 
    (
        A_IN, B_IN : in  std_logic_vector(2 downto 0);
        EQ_OUT     : out std_logic
    );
end my_compare;

architecture structural of my_compare is
    component xnor2
        port 
        (
            in1, in2 : in  std_logic;
            out1     : out std_logic
        );
    end component;

    component and3
        port 
        (
            in1, in2, in3 : in  std_logic;
            out1          : out std_logic
        );
    end component;

    signal p1_out, p2_out, p3_out : std_logic;
begin
    U1: xnor2 port map ( in1 => A_IN(2), in2 => B_IN(2), out1 => p1_out );
    U2: xnor2 port map ( in1 => A_IN(1), in2 => B_IN(1), out1 => p2_out );
    U3: xnor2 port map ( in1 => A_IN(0), in2 => B_IN(0), out1 => p3_out );

    U4: and3  port map ( in1 => p1_out,  in2 => p2_out,  in3 => p3_out, out1 => EQ_OUT );
end structural;