import { ApiInstance } from '@/types';

export class ApiCall {
  private readonly apiInstance: ApiInstance;
  constructor(apiInstance: ApiInstance) {
    this.apiInstance = apiInstance;
  }

  getInstance() {
    return this.apiInstance;
  }

  callApi(type: any, params: any) {
    switch (type) {
      case 'post':
        return this.getInstance().post(params);
    }
  }

  fetchApi(type: any, params: any): any {
    throw new Error('if you want to use fetchApi implements this method');
  }
}

interface LoginDto {
  id: string;
  password: string;
}

interface LoginResponse {
  token: string;
  id: string;
  name: string;
  email: string;
  phone: string;
  address: string;
  status: 'ACTIVE' | 'INACTIVE' | 'NOT_VERIFIED';
}

export class LoginApi extends ApiCall {
  private readonly baseUrl: string;
  constructor(apiInstance: ApiInstance, url: string) {
    super(apiInstance);
    this.baseUrl = url;
  }

  fetchApi(type: string, params: { id: string; password: string }, url?: string) {
    return this.getInstance().post<LoginResponse>(
      this.baseUrl + '/' + (url ? url : 'api/v1/login'),
      {
        data: { ...params },
      },
    );
  }
}

export class ApiContainer {
  public loginApi: LoginApi;
  constructor(apiInstance: ApiInstance) {
    this.loginApi = new LoginApi(apiInstance, 'https://localhost:3000');
  }

  login(type: 'get' | 'post', params: LoginDto) {
    return this.loginApi.fetchApi(type, params);
  }

  call(target: string, dataParams: any) {
    switch (target) {
      case 'login':
        return this.login('post', dataParams);
      default:
        throw new Error('target not found');
    }
  }
}
