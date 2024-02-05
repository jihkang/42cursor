export interface ApiInstance {
  get: <T>(path: string, options?: { params: Record<string, string> }) => Promise<T>;
  post: <T>(path: string, options?: { data: Record<string, string> }) => Promise<T>;
}
