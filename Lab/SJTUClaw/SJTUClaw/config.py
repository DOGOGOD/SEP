"""
DD-SJTUClaw 配置模块
存放 API 相关配置信息，API Key 从本地文件读取，避免泄露。
"""

import os

# API 基础地址
API_BASE_URL = "https://models.sjtu.edu.cn/api/v1"

# API Key 文件路径（相对于项目根目录）
API_KEY_FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "sjtu_api_key")

# 支持的模型列表
SUPPORTED_MODELS = {
    "deepseek-chat": "DeepSeek V3.2 (常规模式)",
    "deepseek-reasoner": "DeepSeek V3.2 (思考模式)",
    "minimax": "MiniMax-M2.7",
    "glm": "GLM-5.1",
    "qwen": "Qwen3.5-27B",
}

# 默认使用的模型
DEFAULT_MODEL = "glm"


def load_api_key() -> str:
    """从本地文件加载 API Key"""
    key_file = os.path.normpath(API_KEY_FILE)
    if not os.path.exists(key_file):
        raise FileNotFoundError(
            f"API Key 文件未找到: {key_file}\n"
            "请在项目根目录创建 sjtu_api_key 文件，并将 API Key 写入其中。"
        )
    with open(key_file, "r", encoding="utf-8") as f:
        key = f.read().strip()
    if not key:
        raise ValueError(f"API Key 文件为空: {key_file}")
    return key
