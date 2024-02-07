export interface ApiInstance {
  get: <T>(path: string, options?: { params: Record<string, string> }) => Promise<T>;
  post: <T>(path: string, options?: { data: Record<string, string> }) => Promise<T>;
}

export interface InputContainerProps {
  type: string;
  id: string;
  name: string;
  placeholder?: string;
  required?: boolean;
  children?: React.ReactNode;
}

export interface ModalProps {
  width?: string;
  height?: string;
  children: React.ReactNode;
  onToggle?: (props?: any) => void;
}
