class TextEditor {
public:
    string text;
    int cursor;
    
    TextEditor() {
        text = "";
        cursor = 0;
    }
    
    void addText(string text) {
        this->text.insert(cursor, text);
        cursor += text.length();
    }
    
    int deleteText(int k) {
        int k_del = 0;
        
        if (cursor >= k) {
            text.erase(cursor-k, k);
            cursor -= k;
            return k;
        } else {
            text.erase(0, cursor);
            k_del = cursor;
            cursor = 0;
            
            return k_del;
        }
    }
    
    string cursorLeft(int k) {
        cursor -= k;
        if (cursor < 0) {
            cursor = 0;
        }
        
        if (cursor >= 10) {
            return text.substr(cursor-10, 10);
        } else {
            return text.substr(0, cursor);
        }
    }
    
    string cursorRight(int k) {
        cursor += k;
        
        if (cursor > text.length()) {
            cursor = text.length();
        }
        
        if (cursor >= 10) {
            return text.substr(cursor-10, 10);
        } else {
            return text.substr(0, cursor);
        }
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
