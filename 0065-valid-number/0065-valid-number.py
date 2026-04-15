STATE_START = 0           # 初始状态
STATE_SIGNED = 1          # 遇到符号后 (如: '+')
STATE_INTEGER = 2         # 遇到整数部分数字后 (如: '12')
STATE_POINT = 3           # 遇到点后 (如: '12.')
STATE_FRACTION = 4        # 遇到小数部分数字后 (如: '12.3')
STATE_EXPONENT = 5        # 遇到指数e/E后 (如: '12e')
STATE_EXPONENT_SIGNED = 6 # 遇到指数符号后 (如: '12e-')
STATE_EXPONENT_INTEGER = 7# 遇到指数整数部分数字后 (如: '12e-3')
STATE_END = 8             # 遇到尾部空格

TYPE_DIGIT, TYPE_SIGN, TYPE_DOT, TYPE_E, TYPE_SPACE, TYPE_INVALID = 0, 1, 2, 3, 4, 5

transition_table = {
    STATE_START: {
        TYPE_SPACE: STATE_START, TYPE_SIGN: STATE_SIGNED, TYPE_DIGIT: STATE_INTEGER, TYPE_DOT: STATE_POINT
    },
    STATE_SIGNED: {
        TYPE_DIGIT: STATE_INTEGER, TYPE_DOT: STATE_POINT
    },
    STATE_INTEGER: {
        TYPE_DIGIT: STATE_INTEGER, TYPE_DOT: STATE_FRACTION, TYPE_E: STATE_EXPONENT, TYPE_SPACE: STATE_END
    },
    STATE_POINT: {
        TYPE_DIGIT: STATE_FRACTION
    },
    STATE_FRACTION: {
        TYPE_DIGIT: STATE_FRACTION, TYPE_E: STATE_EXPONENT, TYPE_SPACE: STATE_END
    },
    STATE_EXPONENT: {
        TYPE_SIGN: STATE_EXPONENT_SIGNED, TYPE_DIGIT: STATE_EXPONENT_INTEGER
    },
    STATE_EXPONENT_SIGNED: {
        TYPE_DIGIT: STATE_EXPONENT_INTEGER
    },
    STATE_EXPONENT_INTEGER: {
        TYPE_DIGIT: STATE_EXPONENT_INTEGER, TYPE_SPACE: STATE_END
    },
    STATE_END: {
        TYPE_SPACE: STATE_END
    }
}

class Solution:
    def isNumber(self, s: str) -> bool:
        def get_type(c):
            if c.isdigit(): return TYPE_DIGIT
            if c in '+-': return TYPE_SIGN
            if c == '.': return TYPE_DOT
            if c in 'eE': return TYPE_E
            if c == ' ': return TYPE_SPACE
            return TYPE_INVALID
        
        valid_end_states = {STATE_INTEGER, STATE_FRACTION, STATE_EXPONENT_INTEGER, STATE_END}

        current_state = STATE_START

        for char in s:
            char_type = get_type(char)

            if char_type not in transition_table[current_state]:
                return False
            
            current_state = transition_table[current_state][char_type]
        
        return current_state in valid_end_states